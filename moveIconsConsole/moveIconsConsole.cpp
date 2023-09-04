// moveIconsConsole.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
//引用了windows.h之后不需要引用winuser.h否则会因为重复声明报错
#include <windows.h>
#include <commctrl.h>
#include<fstream>
#include<atlstr.h>
//把程序转换成UNICODE版的
//由于windows内核采用的是UNICODE，UNICODE版的程序必然比ASCII版的程序效率高
#define UNICODE
#define _UNICODE

//char* CStringToCharArray(CString cstr)
//{
//    int len = WideCharToMultiByte(CP_ACP, 0, cstr, cstr.GetLength(), NULL, 0, NULL, NULL);
//    char* chars = new char[len + 1];
//    WideCharToMultiByte(CP_ACP, 0, cstr, cstr.GetLength(), chars, len, NULL, NULL);
//    chars[len] = '\0';
//    return chars;
//}

int main()
{
    
    //获取到桌面
    HWND hwndWorkerW = 0;
    //表示字符串常量时，不能简单的用双引号括起来，因为那代表ascii字符串。
    //同样也不能在前面加L，因为那代表unicode。
    //我们的程序要做到的是通用性，即不是ascii也不是unicode。所以我们在字符串前应该加的是TEXT
    hwndWorkerW= FindWindowEx(0, hwndWorkerW, TEXT("Progman"), NULL);
    hwndWorkerW = FindWindowEx(hwndWorkerW, 0, TEXT("SHELLDLL_DefView"), NULL);
    hwndWorkerW = FindWindowEx(hwndWorkerW, 0, TEXT("SysListView32"), NULL);
    
    //获取窗口大小
    HWND hd = GetDesktopWindow();
    RECT rect;
    GetClientRect(hd, &rect);
    int client_width = (rect.right - rect.left);
    int client_height = (rect.bottom - rect.top);
    std::cout << "client width:" << client_width << std::endl;
    std::cout << "client height:" << client_height << std::endl;
    //这里是根据移动图标测试出来的，下一行为图标移动的函数
    //SendMessage(hwndWorkerW, LVM_SETITEMPOSITION, 0, MAKELPARAM(client_width + 320, client_height + 90));
    int width = client_width + 320;
    int height = client_height + 90;
    //下面四个坐标划定两个字所在位置
    //SendMessage(hwndWorkerW, LVM_SETITEMPOSITION, 0, MAKELPARAM(18, 20));
    //SendMessage(hwndWorkerW, LVM_SETITEMPOSITION, 1, MAKELPARAM(918, 920));
    //SendMessage(hwndWorkerW, LVM_SETITEMPOSITION, 2, MAKELPARAM(936, 20));
    //SendMessage(hwndWorkerW, LVM_SETITEMPOSITION, 3, MAKELPARAM(1836, 920));

    
    //获取图标数量
    int count = SendMessage(hwndWorkerW, LVM_GETITEMCOUNT, 0, 0);
    std::cout << "count:" << count << std::endl;



    // 测试一下字符串的处理
    //TCHAR FF[50]。FF能装多少字符？哈！不要习惯性的sizeof(FF)了，
    //应该_countof(FF)或者sizeof(FF) / sizeof(TCHAR)。因为我们不确定TCHAR到底是char 还是 wchar_t。、
    //设置本地属性，才可以打印出中文！！！！！！！！！！！！！！！！！！！！
    //setlocale(LC_ALL, "CHS");
    //TCHAR a[20];
    //_tscanf_s(_T("%s"),a,_countof(a));
    //_tprintf(_T("%s\n"),a);
    //LPCTSTR test1=TEXT("这和");
    //_tprintf(_T("%s\n"),test1);

    
    //输入文字
    //setlocale(LC_ALL, "CHS");
    //TCHAR s[6];
    //_tprintf(_T("输入两个文字："));
    //_tscanf_s(_T("%s"), s, _countof(s));
    //_tprintf(_T("%s\n"), s);
    //TCHAR s1 = s[0];
    //TCHAR s2 = s[1];
    

    //输入点阵图
    //int a[16][16];
    //int b[16][16];
    //for (int i = 0; i < 16; i++) {
    //    for (int j = 0; j < 16; j++) {
    //        std::cin >> a[i][j];
    //    }
    //}    
    //for (int i = 0; i < 16; i++) {
    //    for (int j = 0; j < 16; j++) {
    //        std::cin >> b[i][j];
    //    }
    //}
    //for (int i = 0; i < 16; i++) {
    //    for (int j = 0; j < 16; j++) {
    //        std::cout << a[i][j]<<" ";
    //    }
    //    std::cout << std::endl;
    //}
        //执行点阵生成程序
    system("shengcheng.exe");
    //打开文件
    std::ifstream inFile;
    //inFile.open("D://Projects//PythonProjects//小工具//output.txt");
    inFile.open("output.txt");
    int a[16][16];
    int b[16][16];
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            inFile >> a[i][j];
        }
    }
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            inFile >> b[i][j];
        }
    }
    inFile.close();

    //调整图标位置
    //int cur = 0;
    //for (int i = 0; i < 16; i++) {
    //    for (int j = 0; j < 16; j++) {
    //        if (a[i][j] == 1) {
    //            SendMessage(hwndWorkerW, LVM_SETITEMPOSITION, cur++, MAKELPARAM(18+56*j+28, 20+56*i+28));
    //        }
    //        if (cur == count) {
    //            break;
    //        }
    //    }
    //    if (cur == count) {
    //        break;
    //    }
    //}
    //for (int i = 0; i < 16; i++) {
    //    for (int j = 0; j < 16; j++) {
    //        if (b[i][j] == 1) {
    //            SendMessage(hwndWorkerW, LVM_SETITEMPOSITION, cur++, MAKELPARAM(936 + 56 * j + 28, 20 + 56 * i + 28));
    //        }
    //        if (cur == count) {
    //            break;
    //        }
    //    }
    //    if (cur == count) {
    //        break;
    //    }
    //}
    int cur = 0;
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (a[i][j] == 1) {
                SendMessage(hwndWorkerW, LVM_SETITEMPOSITION, cur++, MAKELPARAM(58 * j + 29, 59 * i + 30));
            }
            if (cur == count) {
                break;
            }
        }
        if (cur == count) {
            break;
        }
    }
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (b[i][j] == 1) {
                SendMessage(hwndWorkerW, LVM_SETITEMPOSITION, cur++, MAKELPARAM(928 + 58 * j + 29, 59 * i + 30));
            }
            if (cur == count) {
                break;
            }
        }
        if (cur == count) {
            break;
        }
    }

    //堆叠在一处
    int isPac = 0;
    std::cout << "是否需要堆叠在一处？(1是其余否）" << std::endl;
    std::cin >> isPac;
    if (isPac) {
        for (int i = 0; i < count; i++)
        {
            SendMessage(hwndWorkerW, LVM_SETITEMPOSITION, i, MAKELPARAM(0, 0));
        }
    }
    
    

    // 测试了一下getitemtext函数，不太会用，没成
    //wchar_t pItem[256] = { 0 };
    //LVITEM lvitem;
    //lvitem.cchTextMax = 512;
    //lvitem.iSubItem = 0;
    //lvitem.pszText = pItem;
    //int iItem = 0;
    //::SendMessage(hwndWorkerW, LVM_GETITEMTEXT, (WPARAM)iItem, (LPARAM)&lvitem);


    // 这里会将所有多余的桌面图标放到接们看不见的位置，后面可以右键桌面设置对齐网格还原图标位置
    //for (int i = 0; i < count; i++)
    //{
    //SendMessage(hwndWorkerW, LVM_SETITEMPOSITION, i, MAKELPARAM(-100, -100));
    //   
    //}




    //SendMessage(hwndWorkerW, LVM_SETITEMPOSITION, 0, MAKELPARAM(client_width + 320, client_height+90));
    return 0;
}

