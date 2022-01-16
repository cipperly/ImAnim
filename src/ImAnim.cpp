// ImAnim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <algorithm>
#include <any>
#include <chrono>
#include <functional>
#include <vector>

int test1(int nValue)
{
    std::cout << "test1(" << nValue << ")\n";
    return 10 + nValue;
}

int test2(int nValue)
{
    std::cout << "test2(" << nValue << ")\n";
    return 10 * nValue;
}

class Callback
{
public:

    void append(std::function<int(int)> func)
    {
        m_vecFuncs.push_back(func);
    }

    void invoke(int nValue)
    {
        for (const auto &func : m_vecFuncs)
        {
            std::cout << func(nValue) << '\n';
        }
    }

    void remove(std::function<int(int)> func)
    {
        int (*const *ptr)(int) = func.target<int(*)(int)>();
        if (ptr == nullptr)
        {
            return;
        }

        for (auto iter = m_vecFuncs.begin(); iter != m_vecFuncs.end(); ++iter)
        {
            int (*const *iterPtr)(int) = (*iter).target<int(*)(int)>();
            if ((iterPtr != nullptr) && (*iterPtr == *ptr))
            {
                m_vecFuncs.erase(iter);
                break;
            }
        }
    }

    std::vector<std::function<int(int)>> m_vecFuncs;
};


int main()
{
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch());
    std::cout << "millis since epoch = " << millis.count() << '\n';

    std::vector<std::function<int(int)>> vecCallbacks;
    vecCallbacks.push_back(&test1);
    vecCallbacks.push_back(&test2);
    vecCallbacks.push_back(std::function<int(int)>([](int nValue)
        {
            return nValue;
        }));
    for (const auto& func : vecCallbacks)
    {
        std::cout << func(3) << '\n';
    }
    std::cout << "=================================\n\n\n";

    Callback callback;
    callback.append(&test1);
    callback.append(&test2);
    callback.append([](int nValue)
        {
            return nValue;
        });
    callback.invoke(4);
    callback.remove(&test2);
    std::cout << "=================================\n";
    callback.invoke(4);

    std::cout << "=================================\n\n\n";

    std::vector<std::any> vecFuncs;

    std::function<int(int)> func = &test1;
    vecFuncs.push_back(func);
    vecFuncs.push_back(&test2);

    auto myFunc = std::any_cast<std::function<int(int)>>(vecFuncs[0]);
    std::cout << myFunc(5) << '\n';

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
