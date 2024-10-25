#pragma once

#include <iostream>

template <typename T, typename F>
void	iter(T& arr, int len, F& f)
{
	for (int i=0;i<len;i++)
	{
		f(arr[i]);		
	}
}
