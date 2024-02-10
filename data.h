#pragma once
#ifndef DATA_H//������
#define DATA_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//���ش�����һ�����ݺ���һ����
int get_data(int(*card_on_Hand)[2], int(*rival_out_card)[2], int* nm, vector<string> vs, int pos){
    int i, j, k;
    string s, s1, card;
    vector<string> inhand, inplay,temp_data;//��̬����̫���˻�����vector��
    vector<string> str_get_num(const string & str);
    extern int change_to_num(string s, int num);
    void vector_show(vector<string> v, int type, int begin = 0, int end = 0); //��ʾvector�е�����
    temp_data.clear();//��һ��
    s = vs[pos];  //���n, m
    temp_data = str_get_num(s);
    nm[0] = stoi(temp_data[0]); //n
    nm[1] = stoi(temp_data[1]); //m
    s = vs[pos + 1];  //��������
    inhand = str_get_num(s);//����
    i = pos + 1; //���������ݺ�������1
    for (j = 0; j < 27; j++)
        for (k = 0; k < 2; k++)
            card_on_Hand[j][k] = -1;
    for (j = 0; j < nm[0]; j++)//��ȡת��
    {
        card = inhand[j];
        card_on_Hand[j][0] = change_to_num(card, 0); 
        card_on_Hand[j][1] = change_to_num(card, 1); 
    }
    if (nm[1] > 0)
    {
        i++; //���ϼ����ݣ������������1
        for (j = 0; j < 8; j++)
            for (k = 0; k < 2; k++)
                rival_out_card[j][k] = -1;
        s1 = vs[pos + 2]; //�ϼ�����
        inplay = str_get_num(s1);
        for (j = 0; j < nm[1]; j++)
        {
            card = inplay[j];
            rival_out_card[j][0] = change_to_num(card, 0); 
            rival_out_card[j][1] = change_to_num(card, 1); 
        }
    }
#ifdef DEBUG
    vector_show(vs, 1, pos, i); // ���ÿ�����������,���������Ա�
#endif
    return i + 1;//���������Թ��´ε���
}
vector<string> str_get_num(const string& str)//�ҳ����ݲ�����
{
    vector<string> vstr;
    int i;
    int pos = 0;
    int pos1 = 0;
    int len = str.length();//string����
    for (i = 0; i < len; i++)//����һ�����ݴ���vector vstr
    {
        pos1 = str.find(" ", pos);//find(str�ַ������ߵ����ַ���pos��ʼ����λ��)�����ɹ��ҵ�ƥ������ַ����򷵻ص�һ���ɹ�ƥ������ַ�������������(�����str, �����������pos��ʼ����λ��)�����򷵻�npos
        vstr.push_back(str.substr(pos, pos1 - pos));//��vector�������Ԫ�� s.substr:��pos��ʼ��ȡpos1-pos���ַ�
        pos = pos1 + 1;
    }
    return vstr;
}
void vector_show(vector<string> v, int type, int begin , int end )//������
{
    int i, len;
    begin = 0, end = 0;
    if (v.empty())//���ɶҲû�оͷ���
        return;
    if (type == 0)
    {
        len = v.size();//���
        for (i = 0; i < len; i++)
            cout << v[i] << " " << endl;
    }
    else if (type > 0)
        for (i = begin; i <= end; i++)
            cout << v[i] << " " << endl;
}
#endif

