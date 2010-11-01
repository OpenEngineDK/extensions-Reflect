//
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_REFLECTOR_H_
#define _OE_REFLECTOR_H_

#include <iostream>
#include <Core/IReflectable.h>

#include <map>
#include <string>
#include <vector>

namespace OpenEngine {
namespace Utils {
/**
 * Short description.
 *
 * @class Reflector Reflector.h ons/Reflect/Utils/Reflector.h
 */

using namespace std;

class ReflectedObj;

class Reflector {
private:
    Reflector() {}
    ~Reflector() {}
    Reflector(const Reflector&);
    Reflector& operator=(const Reflector& );

public:
    struct ReflectedField {

    };
    struct ReflectedMethod {
        string name;
        string returntype;
        vector<string> argtypes;
        
        void* (*fun)(Core::IReflectable*, va_list);

    };

    struct ReflectedClass {
        map<string,ReflectedField> fields;
        map<string,ReflectedMethod> methods;
    };
private:
    map<string, ReflectedClass> reflectionMap;
public:
    static Reflector* GetInstance();
    void AddClass(const char* name, ReflectedClass c) {
        reflectionMap[string(name)] = c;
    }
    ReflectedObj* Reflect(Core::IReflectable *obj);
};

class ReflectedObj {
public:
    Core::IReflectable* object;
    Reflector::ReflectedClass reflectedclass;
public:
    void* Call(string fun, ...);
};


} // ns Utils
} // NS OpenEngine

#endif // _OE_REFLECTOR_H_
