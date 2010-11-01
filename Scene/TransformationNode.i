%module Scene

%{
#include <Scene/TransformationNode.h>
 using namespace OpenEngine::Math;
%}

namespace OpenEngine {
namespace Scene {
    class TransformationNode {
 public:
 
    void Move(float x, float y, float z);
    Vector<3,float> GetPosition();
 };
 }
}

