#include "urlAutoFiller.h"
class QtSoapMessage;

urlAutoFiller::urlAutoFiller()
{

}
QString urlAutoFiller::getUrl(QString s){
    QString str=s;
    //QString temp=str.left(7);
    //if(temp.toLower()!="http://"){
    //    str.prepend("http://");
    //}
    /*//search the URL in google
    google.setMethod("GoogleSearch","http://ajax.googleapis.com/ajax/services/search/web");
    google.addMethodArgument("q","",str);
    google.addMethodArgument("v","","1.0");

    http.setHost("ajax.googleapis.com");
    http.submitRequest(google,"/ajax/services/search/web");
    connect(&http, SIGNAL(responseReady()), SLOT(getResponse()));
    qDebug()<<url+" jiong"<<endl;*/
    return str;
}
void urlAutoFiller::getResponse(){
//    const QtSoapMessage &resp = http.getResponse();
 //   const QtSoapType &res = resp.returnValue();
  //  const QtSoapType &resultElement = res["resultElements"][0];
 //   url = resultElement["url"].toString();
}
