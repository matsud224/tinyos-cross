
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_xml_dom_html2_DomHTMLTableColElement__
#define __gnu_xml_dom_html2_DomHTMLTableColElement__

#pragma interface

#include <gnu/xml/dom/html2/DomHTMLElement.h>
extern "Java"
{
  namespace gnu
  {
    namespace xml
    {
      namespace dom
      {
        namespace html2
        {
            class DomHTMLDocument;
            class DomHTMLTableColElement;
        }
      }
    }
  }
}

class gnu::xml::dom::html2::DomHTMLTableColElement : public ::gnu::xml::dom::html2::DomHTMLElement
{

public: // actually protected
  DomHTMLTableColElement(::gnu::xml::dom::html2::DomHTMLDocument *, ::java::lang::String *, ::java::lang::String *);
public:
  virtual ::java::lang::String * getAlign();
  virtual void setAlign(::java::lang::String *);
  virtual ::java::lang::String * getCh();
  virtual void setCh(::java::lang::String *);
  virtual ::java::lang::String * getChOff();
  virtual void setChOff(::java::lang::String *);
  virtual jint getSpan();
  virtual void setSpan(jint);
  virtual ::java::lang::String * getVAlign();
  virtual void setVAlign(::java::lang::String *);
  virtual ::java::lang::String * getWidth();
  virtual void setWidth(::java::lang::String *);
  static ::java::lang::Class class$;
};

#endif // __gnu_xml_dom_html2_DomHTMLTableColElement__
