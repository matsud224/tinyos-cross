
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_imageio_ImageIO$WriterObjectFilter__
#define __javax_imageio_ImageIO$WriterObjectFilter__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace javax
  {
    namespace imageio
    {
        class ImageIO$WriterObjectFilter;
        class ImageTypeSpecifier;
    }
  }
}

class javax::imageio::ImageIO$WriterObjectFilter : public ::java::lang::Object
{

public:
  ImageIO$WriterObjectFilter(::javax::imageio::ImageTypeSpecifier *, ::java::lang::String *);
  jboolean filter(::java::lang::Object *);
private:
  ::javax::imageio::ImageTypeSpecifier * __attribute__((aligned(__alignof__( ::java::lang::Object)))) type;
  ::java::lang::String * formatName;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_imageio_ImageIO$WriterObjectFilter__