// стек.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <Windows.h>
using namespace std;
#pragma warning (disable :4996)
using namespace std;


void Type(char StRing, char openBr, char closeBr, vector <char>& stackk, int& k) { // проверка на скобки 
    if (StRing == openBr) {
        stackk.push_back(StRing);
        k++;
    }
    if (StRing == closeBr) {
        k--;
    }

    if (stackk.size() != 0) {

        if (StRing == closeBr) {
            if (stackk.size() != 0) {
                if ((stackk[stackk.size() - 1] == '(') && (StRing == ')')) {
                    if (stackk.size() != 0) {
                        stackk.pop_back();

                    }
                }
            }
            if (stackk.size() != 0) {
                if ((stackk[stackk.size() - 1] == '{') && (StRing == '}')) {
                    if (stackk.size() != 0) {
                        stackk.pop_back();

                    }
                }
            }
            if (stackk.size() != 0) {
                if ((stackk[stackk.size() - 1] == '[') && (StRing == ']')) {
                    if (stackk.size() != 0) {
                        stackk.pop_back();

                    }
                }
            }
        }
    }
}



double Res(string OPZ, double& x, bool& success,double &input_x) {

    vector <int> stack_number;
    vector <char> stack_func;
    

    for (int i = 0; i < OPZ.size(); i++) {
        if (OPZ[i] == 'x' ) {

            OPZ[i] = input_x+'0';
        }
    }


    for (int i = 0; i < OPZ.size(); i++) {
        

        if (OPZ[i] >= '0' && OPZ[i] <= '9') {

            stack_number.push_back(OPZ[i]);
        }

        if (OPZ[i] >= '*' && OPZ[i] < '0') {
            if (stack_number.size() > 1) {
                switch (OPZ[i]) {

                case '+': {
                    double x1 = (stack_number[stack_number.size() - 1] - '0');
                    double x2 = (stack_number[stack_number.size() - 2] - '0');
                    x = x1 + x2;
                    break;
                }
                case '-': {
                    double x1 = (stack_number[stack_number.size() - 1] - '0');
                    double x2 = (stack_number[stack_number.size() - 2] - '0');
                    x = x1 - x2;
                    break;
                }
                case '*': {
                    double x1 = (stack_number[stack_number.size() - 1] - '0');
                    double x2 = (stack_number[stack_number.size() - 2] - '0');
                    x = x1 * x2;
                    break;
                }
                case '/': {
                    double x1 = (stack_number[stack_number.size() - 1] - '0');
                    double x2 = (stack_number[stack_number.size() - 2] - '0');
                    if (x2 == 0) {
                        cout << "Происходит деление на ноль" << endl;
                        return 0;
                    }
                    else {
                        x = x1 / x2;
                    }
                    break;
                }



                }


                stack_number.pop_back();
                stack_number.pop_back();
                stack_number.push_back(x+'0');
            }
        }
        //cout << stack_number[stack_number.size() - 1] << endl;
    }
    return x;
}


int main()
{
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int k = 0;
    double x = 0;
    bool success = 1;

    vector <char> stack;
    

    string OpenBracketsList = { '(' , '{' , '[' };
    string CloseBracketsList = { ')' , '}' , ']' };
    string out_string;
    string STRING;
    
    cin >> STRING;
     

    if (1) { //Вводная проверка данных 
        for (int i = 0; i < STRING.size(); i++) {
            for (int d = 0; d < 3; d++) {
                Type(STRING[i], OpenBracketsList[d], CloseBracketsList[d], stack, k);
            }
        }
        if (stack.size() != 0) {
            cout << " Проверьте выражение " << endl;
            return 0;
        }
        else {
            if ((stack.size() == 0) && (k == 0)) {
                cout << "Все гуд " << endl;
            }
            else {
                cout << " Проверьте выражение " << endl;
                return 0;
            }
        }
    }


    
    for (int i = 0; i < STRING.size(); i++) { // работа стека 
        //cout << out_string << endl;
        if ((STRING[i] >= '0') && (STRING[i] <= '9') || (STRING[i] == 'x')) { // если число то записываем в выходную строку
            out_string.push_back(STRING[i]);
            
        }

        if ((STRING[i] == '(') || (STRING[i] == '*') || (STRING[i] == '{') || (STRING[i] == '[') || (STRING[i] == '^') || (STRING[i] == '/') || (STRING[i] == '+') || (STRING[i] == '-')) {

            if ((STRING[i] == '+') || (STRING[i] == '-')) {
                if (stack.size() >= 1) {
                    if ((stack[stack.size() - 1] == '-') || (stack[stack.size() - 1] == '+') ||
                        (stack[stack.size() - 1] == '*') || (stack[stack.size() - 1] == '/')) {
                        out_string.push_back(stack[stack.size() - 1]);
                        stack.pop_back();
                    }
                }

            }

            if ((STRING[i] == '*') || (STRING[i] == '/')) {
                if (stack.size() >= 1) {
                    if ((stack[stack.size() - 1] == '*') || (stack[stack.size() - 1] == '/')) {
                        out_string.push_back(stack[stack.size() - 1]);
                        stack.pop_back();
                    }
                }
            }

            if (stack.size() != 0) {
                if ((stack[stack.size() - 1] == '+') && (STRING[i] == '+')) {
                    out_string.push_back(stack[stack.size() - 1]);
                    stack.pop_back();
                }

            }
            if (stack.size() != 0) {
                if ((stack[stack.size() - 1] == '-') && (STRING[i] == '-')) {
                    out_string.push_back(stack[stack.size() - 1]);
                    stack.pop_back();
                }
            }

            stack.push_back(STRING[i]);
        }

        if ((STRING[i] == ')') || (STRING[i] == '}') || (STRING[i] == ']')) {
            if (stack.size() != 0) {
                while ((stack[stack.size() - 1] != '(') ) {
                    if (stack.size() != 0) {
                        out_string.push_back(stack[stack.size() - 1]);

                        cout << out_string << endl;
                        stack.pop_back();
                    }
                }
                if (stack.size() != 0) {
                    if ((stack[stack.size() - 1] != '(') || (stack[stack.size() - 1] != '{') || (stack[stack.size() - 1] != '[')) {
                        stack.pop_back();
                    }
                }
            }
        }



        if (i + 1 == STRING.size()) {

            while (stack.size() != 0) {
                out_string.push_back(stack[stack.size() - 1]);

                stack.pop_back();
            }
        }
    } // опз


    

    cout << "Итог ОПЗ: " << out_string << endl;
    
    double min_input_x = 0;
    double max_input_x = 0;
    double h = 0;
    cout << "Введите начальный X и конечный X и шаг" << endl;
    cin >> min_input_x >> max_input_x >> h;
    if ((h >= 0) && (h < max_input_x)) {
        do  {
            cout << min_input_x << "     " << Res(out_string, x, success, min_input_x) << endl;
            if (min_input_x + h > max_input_x) {
                h = max_input_x - min_input_x;
                
            }
            min_input_x += h;


        } while (min_input_x != max_input_x);
    }
    else {
        cout << "NO" << endl;
    }
    cout << "Ура ура" << endl;



    // 3+4*2/(1-5)^2
    // (1+2)*2+3
    // (1+2)*2+x
    // (1+2)*x+1
    //  1+2*3+(4*5+6)*7

    system("pause");
    return 0;
}