#include "stdafx.h"
#include <iostream>
#include <set>
#include <cstdio>
#pragma warning(disable:4996)

using namespace std;


int main()
{
	FILE *in = fopen("input.txt", "r");
	set<int> s;
	int n, value;
	fscanf(in,"%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		fscanf(in, "%d", &value);
		s.insert(value);
	}
	int data,m,count;
	fscanf(in,"%d",&m);
	for (int i = 1; i <= m; ++i)
	{
		fscanf(in,"%d",&n);
		count=0;
		for (int j = 1; j <= n; ++j)
		{
			fscanf(in,"%d", &data);
			auto it = s.find(data);
			if(it != s.end()) count++;
		}
		cout << count << endl;
	}
	fclose(in);
	return 0;
}


