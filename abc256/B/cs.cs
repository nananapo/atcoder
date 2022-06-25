using System;
using System.Collections.Generic;

public class Program
{
	public static void Main(string []argv)
	{
		int N;
		List<int> A;
		int[] array;

		N = int.Parse(Console.ReadLine());
		A = Console.ReadLine().Split(' ').Select(int.Parse).ToList<int>();
		array = new int[4];

		int	res;
		res = 0;
		foreach(a in A)
		{
			array[0] = 1;
			for (int i=3; i > -1; i--)
			{
				if (i + a >= 4)
					res += array[i];
				else
					array[i + a] = array[i];
				array[i] = 0;
			}
		}

		Console.WriteLine(res.ToString());
	}
}
