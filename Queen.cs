/*
 * 
 * Uses a backtracking algorithm to play x amount of chess queens on an m by n chess 
 * board such that, none of the queens can attack each other
 * 
 * Date Last Modified: 9/1/20
 * author Andrew Rein
 * 
 */
using Microsoft.VisualBasic;
using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace BackTracking_Algorithm
{
    class QueenProblem
    {

        public struct Coord
        {
            public int x;
            public int y;
        };

        private static int rows;
        private static int cols;
        private static int[,] board;
        private static int numQueens;
        private static int placedQueens = 0;

        static List<Coord> sol = new List<Coord>();

        //Checks if any given point falls within the 2D array
        public static bool IsValid(int x, int y)
        {
            if (x >= 0 && y >= 0 && x < rows && y < cols)
            {
                return true;
            }
            else return false;
        }

        //Checks if any given point is safe to place a queen
        static bool IsSafe(int row, int col)
        {

            int nextRow = row;
            int nextCol = col;


            while (IsValid(nextRow - 1, nextCol - 1) == true)
            {

                if (board[nextRow - 1, nextCol - 1] == 1)
                {
                    return false;
                }
                nextRow += -1;
                nextCol += -1;
            }

            nextRow = row;
            nextCol = col;

            while (IsValid(nextRow + 1, nextCol - 1))
            {
                if (board[nextRow + 1, nextCol - 1] == 1)
                {
                    return false;
                }
                nextRow += 1;
                nextCol += -1;
            }

            nextRow = row;
            nextCol = col;

            while (IsValid(nextRow + 1, nextCol + 1))
            {
                if (board[nextRow + 1, nextCol + 1] == 1)
                {
                    return false;
                }
                nextRow += 1;
                nextCol += 1;
            }

            nextRow = row;
            nextCol = col;

            while (IsValid(nextRow - 1, nextCol + 1))
            {
                if (board[nextRow - 1, nextCol + 1] == 1)
                {
                    return false;
                }
                nextRow += -1;
                nextCol += 1;
            }

            for (int i = 0; i < cols; i++)
            {
                if (board[row, i] == 1) return false;
            }

            for (int i = 0; i < rows; i++)
            {
                if (board[i, col] == 1) return false;
            }

            return true;
        }

        private static bool Solve()
        {
            if (PlaceQueens(0, 0) == false)
            {
                Console.WriteLine("Solution does not exist");
                return false;
            }
            else
            {
                PrintBoard();
                Console.WriteLine("Found solution!");
                return true;
            }

        }

        //Backtracks to find the quickest safe placement of the queens
        private static bool PlaceQueens(int row, int col)
        {

            if (placedQueens == numQueens)
            {
                return true;
            }

            for (int i = 0; i < rows; i++)
            {
                if (IsSafe(i, col))
                {

                    placedQueens++;
                    board[i, col] = 1;
                    Coord coord = new Coord();
                    coord.x = i;
                    coord.y = col;
                    sol.Add(coord);

                    if (col + 1 >= cols)
                    {
                        col = -1;
                        i++;
                    }
                    if (PlaceQueens(row, col + 1))
                    {
                        return true;
                    }
                }
                else
                {
                    board[i, col] = 0;
                }
            }

            if (sol.Count != 0) board[sol[sol.Count - 1].x, sol[sol.Count - 1].y] = 0; 
            if (sol.Count != 0) sol.RemoveAt(sol.Count - 1);
            placedQueens--;
            return false;

        }

        //Prints the board at the end of the program for reference
        private static void PrintBoard()
        {
            Console.WriteLine();
            for (int l = 0; l < rows; l++)
            {
                for (int k = 0; k < cols; k++)
                {
                    if (board[l, k] == 1) Console.Write("Q ");
                    else Console.Write(". ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }

        
        public static void Main(String[] args)
        {
            Console.WriteLine("Give the dimensions of the board...");
            rows = Convert.ToInt32(Console.ReadLine());
            cols = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Give the number of queens less than or equal to the columns of the board...");
            numQueens = Convert.ToInt32(Console.ReadLine());
            board = new int[rows, cols];

            for (int i = 0; i < rows; i++)
            {
                for (int k = 0; k < cols; k++)
                {
                    board[i, k] = 0;
                }
            }

            Solve();
        }
    }
}
