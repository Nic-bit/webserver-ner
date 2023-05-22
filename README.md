# webserver-ner
This is a server base on C++11, an it deploy the deep learning ner model to predict text.
## 实体识别
实体识别是NLP(自然语言处理)中的一项基本任务，利用深度学习模型提供识别文本中的命名实体的功能，识别的实体种类包括7个类别：人（PER）、位置（LOC）、交通工具（VEH）、 地理/社会/政治实体（GPE）、武器（WEA）、组织（ORG）、设施（FAC）。如果训练好实体识别的模型，哪怎么把它部署到线上，工业界一般还涉及模型压缩等，这里简单使用前后端的方式来部署训练好的实体识别模型，在网页上输入文字，对输入的文字进行预测，并把抽取的实体信息显示出来。

## 服务器
这里在Linux上采用C++来实现一个高并发的服务器，支持高并发。主要是接受网页上POST上传的文本，然后调用模型预测的服务对文本进行推理识别，再把模型预测得到得实体信息返回给网页。

## 模型部署
模型的部署采用torchserve，torchserve是pytroch官方提供的对在pytorch上训练的模型部署的一个框架，可以把训练好的模型部署启动作为一个REST风格的API，之后可以使用http的方式请求这个API预测文本。

## 框架
![网页通过POST把文本上传给服务器，服务器再请求部署好的模型API预测文本，再把预测得到的结果返回给网页。](https://img-blog.csdnimg.cn/3e590df14b96431bb08d6f6095c840e8.png#pic_center)

## 基于C++实现Webserver服务器并部署深度学习模型


项目简介：基于C++实现Webserver服务器并部署深度学习模型提供在线推理功能。
主要工作：
（1）基于epoll、线程池、定时器等技术实现Webserver服务器，支持并发、解析http请求、支持请求深度学习模型推理结果。
（2）基于Torchserve实现深度学习模型部署，并通过C++的curl库与Webserver服务器进行请求响应交互。在网站通过post上传需要推理的文本或者图片数据，
Webserver收到请求后，把数据传给Torchserve部署好的深度学习模型，模型输出预测结果响应给Webserver，Webserver再响应结果到网站。
（3）支持请求的推理数据批处理，可以部署各种深度学习模型。

![在这里插入图片描述](https://img-blog.csdnimg.cn/0552c9e0f051441f94ee60c98ff608b4.png#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/a847da1f3e0649f4bed1c034f8f5f369.png#pic_center)
