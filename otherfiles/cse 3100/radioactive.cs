using System;

class Program
{
    static int FindRadioactiveBall(int[] balls, Func<int[], bool> isRadioactive)
    {
        int left = 0;
        int right = balls.Length - 1;
        
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int[] group = new int[mid - left + 1];
            Array.Copy(balls, left, group, 0, group.Length);
            
            if (isRadioactive(group))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        
        return balls[left]; // This is the radioactive ball
    }

    static void Main()
    {
        int[] balls = { 1, 2, 3, 4, 5, 6, 7, 8 }; // Example set of balls
        int radioactiveBall = 5; // Ball number 5 is radioactive

        // Simulate the high-tech detection box
        Func<int[], bool> isRadioactive = (group) =>
        {
            foreach (int ball in group)
            {
                if (ball == radioactiveBall) return true;
            }
            return false;
        };

        int foundBall = FindRadioactiveBall(balls, isRadioactive);
        Console.WriteLine($"The radioactive ball is: {foundBall}");
    }
}

