
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_plaf_basic_BasicSplitPaneUI$FocusHandler__
#define __javax_swing_plaf_basic_BasicSplitPaneUI$FocusHandler__

#pragma interface

#include <java/awt/event/FocusAdapter.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
      namespace event
      {
          class FocusEvent;
      }
    }
  }
  namespace javax
  {
    namespace swing
    {
      namespace plaf
      {
        namespace basic
        {
            class BasicSplitPaneUI;
            class BasicSplitPaneUI$FocusHandler;
        }
      }
    }
  }
}

class javax::swing::plaf::basic::BasicSplitPaneUI$FocusHandler : public ::java::awt::event::FocusAdapter
{

public:
  BasicSplitPaneUI$FocusHandler(::javax::swing::plaf::basic::BasicSplitPaneUI *);
  virtual void focusGained(::java::awt::event::FocusEvent *);
  virtual void focusLost(::java::awt::event::FocusEvent *);
public: // actually package-private
  ::javax::swing::plaf::basic::BasicSplitPaneUI * __attribute__((aligned(__alignof__( ::java::awt::event::FocusAdapter)))) this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_plaf_basic_BasicSplitPaneUI$FocusHandler__
