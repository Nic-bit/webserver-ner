#include"curl_ner.h"
 
static size_t cb(void *data, size_t size, size_t nmemb, void *userp)
{
   size_t realsize = size * nmemb;
   struct memory *mem = (struct memory *)userp;
 
   char *ptr = (char*)realloc(mem->response, mem->size + realsize + 1);
   if(ptr == NULL)
     return 0;  /* out of memory! */
 
   mem->response = ptr;
   memcpy(&(mem->response[mem->size]), data, realsize);
   mem->size += realsize;
   mem->response[mem->size] = 0;
 
   return realsize;
}


bool ner(char *text,struct memory *buf)
{
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl)
    {
        //curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "/tmp/cookie.txt"); // 指定cookie文件
        int str_len = strlen(text);
        char* input_text = (char *)malloc(str_len+6);// data= \0 需要额外6个byte
        memset(input_text,'\0',str_len + 1);
        strcat(input_text,"data=");
        strcat(input_text,text);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, input_text);    // 指定post内容
        //curl_easy_setopt(curl, CURLOPT_PROXY, "127.0.0.1:8080");
        curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:8080/predictions/my_tc");   // 指定url
        /* send all data to this function  */
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)buf);
        
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        free(input_text);

    }
    // printf("curl:%s\n",buf->response);
    // printf("curl size:%d\n",buf->size);

    return true;
}