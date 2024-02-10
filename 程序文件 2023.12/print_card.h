#pragma once
#include<iostream>//存链接的各个函数
using namespace std;
extern void get_small_pair(int(*hand)[2], int(*play)[2], int n, int m, int level);
extern void get_small_three_pair(int(*hand)[2], int(*play)[2], int n, int m, int level);
extern void get_small_three(int(*hand)[2], int(*play)[2], int n, int m, int level);
extern void get_small_double_three(int(*hand)[2], int(*play)[2], int n, int m, int level);
extern void get_small_three_two(int(*hand)[2], int(*play)[2], int n, int m, int level);
extern void get_small_five(int(*hand)[2], int(*play)[2], int n, int m, int level);
extern void get_small_bomb(int(*hand)[2], int(*play)[2], int n, int m, int level);
extern void pass(int(*hand)[2], int n);
extern void card_sort(int(*array)[2], int n, int level);
extern int card_type(int(*play)[2], int m);
extern void delete_card(int(*hand)[2],int (*play)[2],int n, int m,int level);
extern void find_min(int(*hand)[2], int(*play)[2], int n, int m, int level);
extern void run_card(int(*hand)[2], int(*play)[2], int n, int m, int level);
extern void out_card(int(*temp)[2], int(*hand)[2], int j, int n);
extern int find_bomb(int(*temp)[2], int(*hand)[2], int n, int level, int type);
extern void hand_count(int(*base)[2], int(*hand)[2], int n, int level);
extern void non_level_base(int(*base)[2], int level);
extern int deal_streight_five(int(*base)[2], int(*streight_five)[2], int(*hand_temp)[2], int count, int level);
extern int deal_bomb(int(*base)[2], int(*bomb)[2], int(*king)[2], int(*hand)[2], int(*hand_temp)[2], int n);
extern void deal_five(int(*base)[2], int(*five)[2], int(*hand_temp)[2], int count);
extern string change_to_string(int cardnum, int n);
extern int judge_bomb(int(*temp)[2], int(*hand)[2], int n, int m, int level, int face);
extern void run_card_1(int(*hand)[2], int(*play)[2], int n, int m, int level);