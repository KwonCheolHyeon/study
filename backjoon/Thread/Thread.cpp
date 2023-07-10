//#include <iostream>
//#include <thread>
//
//using namespace std;
//
///*
// * 함수포인트를 사용한 Thread 에제
// * 유의 사항 : default Parametar는 사용 할 수 없다.
// */
//void func_type_thread(int count) {
//    for (int i = 1; i <= count; i++) {
//        cout << "func point type : count " << i << endl;
//    }
//}
//
///*
// * class내 부의 static 함수화 멤버 함수를 사용한 Thread 예제
// */
//class thread_test
//{
//public:
//    static void class_static_func_type_thread(int count) {
//        for (int i = 1; i <= count; i++) {
//            cout << "class static func type : count " << i << endl;
//        }
//    }
//
//    void class_func_type_thread(int count) {
//        for (int i = 1; i <= count; i++) {
//            cout << "class func type : count " << i << endl;
//        }
//    }
//
//};
//
//int main() {
//    // 1. C 스타일 thread 생성 (함수 포인트 활용)
//    thread thread1 = thread(func_type_thread, 10);
//
//    // 2. Class의 Static 함수를 사용한 Thread 생성
//    thread thread2 = thread(thread_test::class_static_func_type_thread, 10);
//
//    // 3. Class의 멤버 함수를 사용한 Thread 생성
//    thread thread3 = thread(&thread_test::class_func_type_thread, thread_test(), 10);
//
//    // 4. lamda를 사용하여 Class의 멤버 함수를 Thread로 생성
//    thread thread4([](int count) {
//        thread_test tt4;
//        tt4.class_func_type_thread(count);
//        }, 10);
//
//    // 5. lambda 를 사용한 Thread 생성
//    thread thread5([](int count) {
//        for (int i = 1; i <= count; i++) {
//            cout << "lambda type : count " << i << endl;
//        }
//        }, 10);
//
//
//    thread1.join();
//    thread2.join();
//    thread3.join();
//    thread4.join();
//    thread5.join();
//    return 0;
//}