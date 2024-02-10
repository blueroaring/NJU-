#pragma once
#ifndef DATA_H//测试用
#define DATA_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//返回处理后的一组数据和下一行数
int get_data(int(*card_on_Hand)[2], int(*rival_out_card)[2], int* nm, vector<string> vs, int pos){
    int i, j, k;
    string s, s1, card;
    vector<string> inhand, inplay,temp_data;//动态数组太蠢了还是用vector了
    vector<string> str_get_num(const string & str);
    extern int change_to_num(string s, int num);
    void vector_show(vector<string> v, int type, int begin = 0, int end = 0); //显示vector中的数据
    temp_data.clear();//清一下
    s = vs[pos];  //获得n, m
    temp_data = str_get_num(s);
    nm[0] = stoi(temp_data[0]); //n
    nm[1] = stoi(temp_data[1]); //m
    s = vs[pos + 1];  //手牌数据
    inhand = str_get_num(s);//读入
    i = pos + 1; //读手牌数据后行数加1
    for (j = 0; j < 27; j++)
        for (k = 0; k < 2; k++)
            card_on_Hand[j][k] = -1;
    for (j = 0; j < nm[0]; j++)//读取转换
    {
        card = inhand[j];
        card_on_Hand[j][0] = change_to_num(card, 0); 
        card_on_Hand[j][1] = change_to_num(card, 1); 
    }
    if (nm[1] > 0)
    {
        i++; //有上家数据，读入后行数加1
        for (j = 0; j < 8; j++)
            for (k = 0; k < 2; k++)
                rival_out_card[j][k] = -1;
        s1 = vs[pos + 2]; //上家数据
        inplay = str_get_num(s1);
        for (j = 0; j < nm[1]; j++)
        {
            card = inplay[j];
            rival_out_card[j][0] = change_to_num(card, 0); 
            rival_out_card[j][1] = change_to_num(card, 1); 
        }
    }
#ifdef DEBUG
    vector_show(vs, 1, pos, i); // 输出每次输入的数据,方便和输出对比
#endif
    return i + 1;//返回行数以供下次调用
}
vector<string> str_get_num(const string& str)//找出数据并存入
{
    vector<string> vstr;
    int i;
    int pos = 0;
    int pos1 = 0;
    int len = str.length();//string长度
    for (i = 0; i < len; i++)//将这一行数据存入vector vstr
    {
        pos1 = str.find(" ", pos);//find(str字符串或者单个字符，pos起始搜索位置)，若成功找到匹配的子字符串则返回第一个成功匹配的子字符串的索引坐标(相对于str, 而不是相对于pos起始搜索位置)，否则返回npos
        vstr.push_back(str.substr(pos, pos1 - pos));//在vector后面添加元素 s.substr:从pos开始截取pos1-pos个字符
        pos = pos1 + 1;
    }
    return vstr;
}
void vector_show(vector<string> v, int type, int begin , int end )//测试用
{
    int i, len;
    begin = 0, end = 0;
    if (v.empty())//如果啥也没有就返回
        return;
    if (type == 0)
    {
        len = v.size();//输出
        for (i = 0; i < len; i++)
            cout << v[i] << " " << endl;
    }
    else if (type > 0)
        for (i = begin; i <= end; i++)
            cout << v[i] << " " << endl;
}
#endif

