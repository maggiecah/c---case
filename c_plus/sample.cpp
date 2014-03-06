#include <iostream.h>
using namespace std;
class Simple {
     public:
           Simple(int param = 0) {
                   number = param;
                       std::cout << "Simple: " << number << std::endl; 
                         }
            
             ~Simple() {
                     std::cout << "~Simple: " << number << std::endl;
                       }
              
               void PrintSomething() {
                       std::cout << "PrintSomething: " << info_extend.c_str() << std::endl;
                         }
                
                 std::string info_extend;
                   int number;
};
void TestAutoPtr() {
    std::auto_ptr<Simple> my_memory(new Simple(1));   // 创建对象，输出：Simple：1
    if (my_memory.get()) {                            // 判断智能指针是否为空
        my_memory->PrintSomething();                    // 使用 operator-> 调用智能指针对象中的函数
        my_memory.get()->info_extend = "Addition";      // 使用 get() 返回裸指针，然后给内部对象赋值
        my_memory->PrintSomething();                    // 再次打印，表明上述赋值成功
        (*my_memory).info_extend += " other";           // 使用 operator* 返回智能指针内部对象，然后用“.”调用智能指针对象中的函数
        my_memory->PrintSomething();                    // 再次打印，表明上述赋值成功
        std:auto_ptr<Simple> my_memory2;
       //my_memory =my_memory2;
    }
    std::cout << "hi" << std::endl;
}      

int main()
{
    TestAutoPtr();
}
