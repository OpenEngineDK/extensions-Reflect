#include "Reflector.h"   
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Utils {
    Reflector* Reflector::GetInstance() {
        static Reflector* _instance = 0;
        if (!_instance) {
            _instance = new Reflector();
        }
        return _instance;
    }

    ReflectedObj* Reflector::Reflect(Core::IReflectable *obj) {
        ReflectedObj *r =  new ReflectedObj();
        r->object = obj;
        r->reflectedclass = reflectionMap[typeid(*obj).name()];
        return r;
    }

    void* ReflectedObj::Call(string fname, ...) {
        va_list va;
        
        Reflector::ReflectedMethod m = reflectedclass.methods[fname];
        va_start(va,fname);
        
        
        
        void *o = (m.fun)(object, va);
        va_end(va);

        return o;
    }
}
}
