#include"curl_ner.cpp"

int main(void)
{
    char *text = "贵州大学是一所学校";
    struct memory buf = {0};
  
    ner(text,&buf);
    printf("buf:[%s]\n",buf.response);
    printf("size:[%ld]\n",buf.size);

    return 0;
    
    //bool ner(char *text,struct memory *buf)
    
}