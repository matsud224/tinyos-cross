
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_dnd_DropTarget__
#define __java_awt_dnd_DropTarget__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class Component;
        class Point;
      namespace datatransfer
      {
          class FlavorMap;
      }
      namespace dnd
      {
          class DropTarget;
          class DropTarget$DropTargetAutoScroller;
          class DropTargetContext;
          class DropTargetDragEvent;
          class DropTargetDropEvent;
          class DropTargetEvent;
          class DropTargetListener;
        namespace peer
        {
            class DropTargetPeer;
        }
      }
      namespace peer
      {
          class ComponentPeer;
      }
    }
  }
}

class java::awt::dnd::DropTarget : public ::java::lang::Object
{

public:
  DropTarget();
  DropTarget(::java::awt::Component *, ::java::awt::dnd::DropTargetListener *);
  DropTarget(::java::awt::Component *, jint, ::java::awt::dnd::DropTargetListener *);
  DropTarget(::java::awt::Component *, jint, ::java::awt::dnd::DropTargetListener *, jboolean);
  DropTarget(::java::awt::Component *, jint, ::java::awt::dnd::DropTargetListener *, jboolean, ::java::awt::datatransfer::FlavorMap *);
  virtual void setComponent(::java::awt::Component *);
  virtual ::java::awt::Component * getComponent();
  virtual void setDefaultActions(jint);
  virtual jint getDefaultActions();
  virtual void setActive(jboolean);
  virtual jboolean isActive();
  virtual void addDropTargetListener(::java::awt::dnd::DropTargetListener *);
  virtual void removeDropTargetListener(::java::awt::dnd::DropTargetListener *);
  virtual void dragEnter(::java::awt::dnd::DropTargetDragEvent *);
  virtual void dragOver(::java::awt::dnd::DropTargetDragEvent *);
  virtual void dropActionChanged(::java::awt::dnd::DropTargetDragEvent *);
  virtual void dragExit(::java::awt::dnd::DropTargetEvent *);
  virtual void drop(::java::awt::dnd::DropTargetDropEvent *);
  virtual ::java::awt::datatransfer::FlavorMap * getFlavorMap();
  virtual void setFlavorMap(::java::awt::datatransfer::FlavorMap *);
  virtual void addNotify(::java::awt::peer::ComponentPeer *);
  virtual void removeNotify(::java::awt::peer::ComponentPeer *);
  virtual ::java::awt::dnd::DropTargetContext * getDropTargetContext();
public: // actually protected
  virtual ::java::awt::dnd::DropTargetContext * createDropTargetContext();
  virtual ::java::awt::dnd::DropTarget$DropTargetAutoScroller * createDropTargetAutoScroller(::java::awt::Component *, ::java::awt::Point *);
  virtual void initializeAutoscrolling(::java::awt::Point *);
  virtual void updateAutoscroll(::java::awt::Point *);
  virtual void clearAutoscroll();
private:
  static const jlong serialVersionUID = -6283860791671019047LL;
  ::java::awt::Component * __attribute__((aligned(__alignof__( ::java::lang::Object)))) component;
  ::java::awt::datatransfer::FlavorMap * flavorMap;
  jint actions;
  ::java::awt::dnd::peer::DropTargetPeer * peer;
  ::java::awt::dnd::DropTargetContext * dropTargetContext;
  ::java::awt::dnd::DropTargetListener * dropTargetListener;
  ::java::awt::dnd::DropTarget$DropTargetAutoScroller * autoscroller;
  jboolean active;
public:
  static ::java::lang::Class class$;
};

#endif // __java_awt_dnd_DropTarget__
