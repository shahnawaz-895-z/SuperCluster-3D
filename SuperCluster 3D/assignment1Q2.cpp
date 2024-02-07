#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
#include<ctime>
#include<cmath>
using namespace std;

int main()
{
    srand(time(NULL));  // seed the random number generator




    int count = 0;
    string array[250][5];
    ifstream file("question_2.csv");
    double array2[250][3]{ 0 };





    cout << "id\tage\tspeed\n";
    if (file.is_open())
    {
        int i = 0;

        cout << "Successfully open file" << endl;

        string id, gender, age,income,score;
        getline(file, id, ',');
        getline(file, gender, ',');
        getline(file, age, ',');
        getline(file, income, ',');
        getline(file, score, '\n');
        while (file.good())
        {
            getline(file, id, ',');
            getline(file, gender, ',');
            getline(file, age, ',');
            getline(file, income, ',');
            getline(file, score, '\n');
            //cout << id << "\t" << dist << "\t" << speed << endl;
            for (int i = 0; i < 5; i++)   //this loop is to storing valaues in the string array
            {

                if (i == 0) {

                    array[count][i] = id;
                }
                else if (i == 1)
                {
                    array[count][i] = gender;
                }
                else if (i == 2)
                {
                    array[count][i] = age;
                }
                else if (i == 3)
                {
                    array[count][i] = income;
                }
                else if (i == 4)
                {
                    array[count][i] = score;
                }
                /*else
                    array[count][i] = " ";*/
            }

            for (int j = 0; j < 3; j++) //this is for storing value in float array
            {
                if (j == 0)
                {
                    array2[count][j] = stold(age);
                }
                else if (j == 1)
                {
                    array2[count][j] = stold(income);
                }
                else if (j == 2)
                {
                    array2[count][j] = stold(score);
                }
            }
            count++;

        }
    }
    count -= 1;
    cout << count << endl;
    cout << "id\tdist\tspeed\n";

    //for (int i = 0; i < count; i++)
    //{
    //    for (int j = 0; j < 3; j++)
    //    {
    //        cout << array[i][j] << "\t";
    //    }
    //    cout << endl;
    //}


    //for (int i = 0; i < count; i++)
    //{
    //    for (int j = 0; j < 2; j++)
    //    {
    //        cout << array2[i][j] << "\t";
    //    }
    //    cout << endl;
    //}

    int r1 = (rand() % 200) + 1;//for genrating randum number 
    int r2 = (rand() % 200) + 1;
    int r3 = (rand() % 200) + 1;
    int r4 = (rand() % 200) + 1;
    cout << "number 1\tnumber 2\tnumber 3\tnumber 4\t\n";
    cout << r1 << "\t\t" << r2 << "\t\t" << r3 << "\t\t" << r4 << "\t\t\n";

    double c1_age = array2[r1 - 2][0]; //assigning value of form randum index to speed and dist
    double c2_age = array2[r2 - 2][0];
    double c3_age = array2[r3 - 2][0];
    double c4_age = array2[r4 - 2][0];
    double c1_income = array2[r1 - 2][1];
    double c2_income = array2[r2 - 2][1];
    double c3_income = array2[r3 - 2][1];
    double c4_income = array2[r4 - 2][1];

    double c1_score = array2[r1 - 2][2];
    double c2_score = array2[r2 - 2][2];
    double c3_score = array2[r3 - 2][2];
    double c4_score = array2[r4 - 2][2];

    float c1[205]{ 0 };
    float c2[205]{ 0 };
    float c3[205]{ 0 };
    float c4[205]{ 0 };
    double k_1[205][3]{ 0 }; //for aassigning the value of speed and dist to its near centroid
    double k_2[205][3]{ 0 };
    double k_3[205][3]{ 0 };
    double k_4[205][3]{ 0 };
    int x1 = 0, x2 = 0, x3 = 0, x4 = 0;//size of all centroid array
    double c_2_1_age = 0;
    double c_2_2_age = 0;
    double c_2_3_age = 0;
    double c_2_4_age = 0;
    double c_2_1_income = 0;
    double c_2_2_income = 0;
    double c_2_3_income = 0;
    double c_2_4_income = 0;
    double c_2_1_score = 0;
    double c_2_2_score = 0;
    double c_2_3_score = 0;
    double c_2_4_score = 0;
    //int index_c1[4500]{ 0 };
  /*  int index_c2[4500]{ 0 };
    int index_c3[4500]{ 0 };
    int index_c4[4500]{ 0 };*/

    int center_array[205]{ 0 };


    double sum1 = 0;
    double sum2 = 0;
    double sum3 = 0;
    float dif = 0;
kmean:


    /* for (int i = 0; i < 4500; i++)
     {

         index_c1[i] = 0;
         index_c2[i] = 0;
         index_c3[i] = 0;
         index_c4[i] = 0;
         c1[i] = 0;
         c2[i] = 0;
         c3[i] = 0;
         c4[i] = 0;
         center_array[i] = 0;
     }*/
    //cout << "centeroid 1 on random number " << r1 << " is  (" << c1_age << ", " << c1_income <<"," <<  c1_score << ")  " << endl; ;
    //cout << "centeroid 2 on random number " << r2 << " is  (" << c2_age << ", " << c2_income << "," << c2_score << ")  " << endl; ;
    //cout << "centeroid 3 on random number " << r3 << " is  (" << c3_age << ", " << c3_income << "," << c3_score << ")  " << endl; ;
    //cout << "centeroid 4 on random number " << r4 << " is  (" << c4_age << ", " << c3_income << "," << c3_score << ")  " << endl; ;
    sum1 = 0;
    sum2 = 0;
    sum3 = 0;
    dif = 0;
    x1 = 0; x2 = 0; x3 = 0; x4 = 0;
    for (int i = 0; i < count; i++)//this loop is for calculating different from every point
    {
        dif = sqrt(((array2[i][0] - c1_age) * (array2[i][0] - c1_age)) + ((array2[i][1] - c1_income) * (array2[i][1] - c1_income))+ ((array2[i][2] - c1_score) * (array2[i][2] - c1_score)));
        c1[i] = dif;                                                                                                      
        dif = sqrt(((array2[i][0] - c2_age) * (array2[i][0] - c2_age)) + ((array2[i][1] - c2_income) * (array2[i][1] - c2_income))+ ((array2[i][2] - c2_score) * (array2[i][2] - c2_score)));
        c2[i] = dif;                                                                                                     
        dif = sqrt(((array2[i][0] - c3_age) * (array2[i][0] - c3_age)) + ((array2[i][1] - c3_income) * (array2[i][1] - c3_income)) + ((array2[i][2] - c3_score) * (array2[i][2] - c3_score)));
        c3[i] = dif;
        dif = sqrt(((array2[i][0] - c4_age) * (array2[i][0] - c4_age)) + ((array2[i][1] - c4_income) * (array2[i][1] - c4_income)) + ((array2[i][2] - c4_score) * (array2[i][2] - c4_score)));
        c4[i] = dif;

    }









    //// dif = sqrt((array2[r1-2][0] - c1_dist) * (array2[r1-2][0] - c1_dist)) + ((array2[r1-2][1] - c1_speed) * (array2[r1-2][1] - c1_speed));
    //for (int i = 0; i < count; i++)
    //{
    //    // cout <<i<<"  :   " << c1[i] << "\t\t" << c2[i] << "\t\t" << c3[i] << "\t\t" << c4[i] << endl;
    //}

    for (int i = 0; i < count; i++)
    {
        if ((c1[i] < c2[i]) && (c1[i] < c3[i]) && (c1[i] < c4[i]))
        {
            k_1[x1][0] = array2[i][0];
            sum1 += k_1[x1][0];

            k_1[x1][1] = array2[i][1];

            sum2 += k_1[x1][1];
            k_1[x1][2] = array2[i][2];
            sum3 += k_1[x1][2];

            // index_c1[x1] = i;
            center_array[i] = 1;
            x1++;
        }

        else if (c1[i] == c2[i] && (c1[i] < c3[i]) && (c1[i] < c4[i]))
        {
            k_1[x1][0] = array2[i][0];
            sum1 += k_1[x1][0];

            k_1[x1][1] = array2[i][1];

            sum2 += k_1[x1][1];
            k_1[x1][2] = array2[i][2];
            sum3 += k_1[x1][2];
            /// index_c1[x1] = i;
            center_array[i] = 1;
            x1++;
        }
        else if (c1[i] < c2[i] && (c1[i] == c3[i]) && (c1[i] < c4[i]))
        {
            k_1[x1][0] = array2[i][0];
            sum1 += k_1[x1][0];

            k_1[x1][1] = array2[i][1];

            sum2 += k_1[x1][1];
            k_1[x1][2] = array2[i][2];
            sum3 += k_1[x1][2];

            // index_c1[x1] = i;
            center_array[i] = 1;
            x1++;
        }

        else if (c1[i] < c2[i] && (c1[i] < c3[i]) && (c1[i] == c4[i]))
        {
            k_1[x1][0] = array2[i][0];
            sum1 += k_1[x1][0];

            k_1[x1][1] = array2[i][1];

            sum2 += k_1[x1][1];

            k_1[x1][2] = array2[i][2];
            sum3 += k_1[x1][2];
            // index_c1[x1] = i;
            center_array[i] = 1;
            x1++;
        }

        else if (c1[i] == c2[i] && (c1[i] == c3[i]) && (c1[i] < c4[i]))
        {
            k_1[x1][0] = array2[i][0];
            sum1 += k_1[x1][0];

            k_1[x1][1] = array2[i][1];

            sum2 += k_1[x1][1];

            k_1[x1][2] = array2[i][2];
            sum3 += k_1[x1][2];
            // index_c1[x1] = i;
            center_array[i] = 1;
            x1++;
        }
        else if (c1[i] < c2[i] && (c1[i] == c3[i]) && (c1[i] == c4[i]))
        {
            k_1[x1][0] = array2[i][0];
            sum1 += k_1[x1][0];

            k_1[x1][1] = array2[i][1];

            sum2 += k_1[x1][1];
            k_1[x1][2] = array2[i][2];
            sum3 += k_1[x1][2];
            // index_c1[x1] = i;
            center_array[i] = 1;
            x1++;
        }

        else if (c1[i] == c2[i] && (c1[i] == c3[i]) && (c1[i] == c4[i]))
        {
            if (c4[i] == 0 || c3[i] == 0 || c2[i] == 0)
            {
                break;
            }
            else
            {

                k_1[x1][0] = array2[i][0];
                sum1 += k_1[x1][0];

                k_1[x1][1] = array2[i][1];

                sum2 += k_1[x1][1];
                k_1[x1][2] = array2[i][2];
                sum3 += k_1[x1][2];
                center_array[i] = 1;
                x1++;
            }
        }
    }


    c_2_1_age = sum1 / x1;
    c_2_1_income = sum2 / x1;
    c_2_1_score = sum3 / x1;

    cout << "centeroid 1 number " << " is  (" << c_2_1_age << ", " << c_2_1_income << "," << c_2_1_score << ")  " << endl; 
    sum1 = 0;
    sum2 = 0;
    sum3 = 0;

    for (int i = 0; i < count; i++)
    {
        if ((c2[i] < c1[i]) && (c2[i] < c3[i]) && (c2[i] < c4[i]))
        {
            k_2[x2][0] = array2[i][0];
            sum1 += k_2[x2][0];
            k_2[x2][1] = array2[i][1];
            sum2 += k_2[x2][1];

            k_2[x2][2] = array2[i][2];
            sum3 += k_2[x2][2];

            // index_c2[x2] = i;
            center_array[i] = 2;
            x2++;
        }
        else if ((c2[i] < c1[i]) && (c2[i] == c3[i]) && (c2[i] < c4[i]))
        {
            k_2[x2][0] = array2[i][0];
            sum1 += k_2[x2][0];
            k_2[x2][1] = array2[i][1];
            sum2 += k_2[x2][1];
            k_2[x2][2] = array2[i][2];
            sum3 += k_2[x2][2];
            // index_c2[x2] = i;
            center_array[i] = 2;
            x2++;
        }

        else if ((c2[i] < c1[i]) && (c2[i] < c3[i]) && (c2[i] == c4[i]))
        {
            k_2[x2][0] = array2[i][0];
            sum1 += k_2[x2][0];
            k_2[x2][1] = array2[i][1];
            sum2 += k_2[x2][1];
            k_2[x2][2] = array2[i][2];
            sum3 += k_2[x2][2];
            // index_c2[x2] = i;
            center_array[i] = 2;
            x2++;
        }
        else if ((c2[i] < c1[i]) && (c2[i] == c3[i]) && (c2[i] == c4[i]))
        {
            k_2[x2][0] = array2[i][0];
            sum1 += k_2[x2][0];
            k_2[x2][1] = array2[i][1];
            sum2 += k_2[x2][1];
            k_2[x2][2] = array2[i][2];
            sum3 += k_2[x2][2];

            // index_c2[x2] = i;
            center_array[i] = 2;
            x2++;
        }
        /*

        else if ((c2[i] < c1[i]) && (c2[i] == c3[i]) && (c2[i] < c4[i]))
        {
            k_2[i] = c2[i];
            x2++;
        }
        else if ((c2[i] < c1[i]) && (c2[i] < c3[i]) && (c2[i] == c4[i]))
        {
            k_2[i] = c2[i];
            x2++;
        }*/

    }

    c_2_2_age = sum1 / x2;
    c_2_2_income = sum2 / x2;
    c_2_2_score = sum3 / x2;

    cout << "centeroid 1 number " << " is  (" << c_2_2_age << ", " << c_2_2_income << ","<< c_2_2_score << ")  " << endl;
    sum1 = 0;
    sum2 = 0;
    sum3 = 0;


    for (int i = 0; i < count; i++)
    {
        if ((c3[i] < c1[i]) && (c3[i] < c2[i]) && (c3[i] < c4[i]))
        {
            k_3[x3][0] = array2[i][0];
            sum1 += k_3[x3][0];
            k_3[x3][1] = array2[i][1];
            sum2 += k_3[x3][1];

            k_3[x3][2] = array2[i][2];
            sum3 += k_3[x3][2];

            // index_c3[x3] = i;
            center_array[i] = 3;
            x3++;
        }
        else if ((c3[i] < c1[i]) && (c3[i] < c2[i]) && (c3[i] == c4[i]))
        {
            k_3[x3][0] = array2[i][0];
            sum1 += k_3[x3][0];
            k_3[x3][1] = array2[i][1];
            sum2 += k_3[x3][1];
            k_3[x3][2] = array2[i][2];
            sum3 += k_3[x3][2];

            // index_c3[x3] = i;
            center_array[i] = 3;
            x3++;

        }

        /*else if ((c3[i] <  c1[i]) && (c3[i] == c2[i]) && (c3[i] < c4[i]))
        {
            k_3[i] = c3[i];
            x3++;
        }*/
        //else if ((c3[i] < c1[i]) && (c3[i] < c2[i]) && (c3[i] == c4[i]))
        //{
        //    k_3[i] = c3[i];
        //    x3++;
        //}
    }
    c_2_3_age = sum1 / x3;
    c_2_3_income = sum2 / x3;
    c_2_3_score = sum3 / x3;

    cout << "centeroid 1 number " << " is  (" << c_2_3_age << ", " << c_2_3_income << "," << c_2_3_score << ")  " << endl;

    sum1 = 0;
    sum2 = 0;
    sum3 = 0;


    for (int i = 0; i < count; i++)
    {
        if ((c4[i] < c1[i]) && (c4[i] < c2[i]) && (c4[i] < c3[i]))
        {
            k_4[x4][0] = array2[i][0];
            sum1 += k_4[x4][0];
            k_4[x4][1] = array2[i][1];
            sum2 += k_4[x4][1];
            k_4[x4][2] = array2[i][2];
            sum2 += k_4[x4][2];

            //  index_c4[x4] = i;
            center_array[i] = 4;
            x4++;
        }
        /* else if ((c4[i] == c1[i]) && (c4[i] < c2[i]) && (c4[i] < c3[i]))
         {
             k_4[i] = c4[i];
             x4++;
         }
         else if ((c4[i] < c1[i]) && (c4[i] == c2[i]) && (c4[i] < c3[i]))
         {
             k_4[i] = c4[i];
             x4++;
         }*/
         /*else if ((c4[i] < c1[i]) && (c4[i] < c2[i]) && (c4[i] == c3[i]))
         {
             k_4[i] = c4[i];
             x4++;
         }*/

    }

    c_2_4_age = sum1 / x4;
    c_2_4_income = sum2 / x4;
    c_2_4_score = sum3 / x4;

    cout << "centeroid 1 number " << " is  (" << c_2_4_age << ", " << c_2_4_income << "," << c_2_4_score << ")  " << endl;
    sum1 = 0;
    sum2 = 0;
    sum3 = 0;
    int x = x1 + x2 + x3 + x4;
    cout << x1 << "\t\t" << x2 << "\t\t" << x3 << "\t\t" << x4 << endl;
    cout << x << endl;
    cout << "\n\n\n\n" << endl;
    cout << c_2_1_age << "====" << c1_age << "        " << c_2_2_age << "====" << c2_age << endl;
    cout << c_2_3_age << "====" << c3_age << "        " << c_2_4_age << "====" << c4_age << endl;
    cout << "\n\n\n\n" << endl;
    if ((c_2_1_age == c1_age) && (c_2_2_age == c2_age) && (c_2_3_age == c3_age) && (c_2_4_age == c4_age))

    {
        cout << "    so the priviouse and recent centeroid become equal  " << endl;
        cout << endl;

    }
    else
    {
        //cout << " elsee condition  " << endl;
        c1_age = c_2_1_age;
        c2_age = c_2_2_age;
        c3_age = c_2_3_age;
        c4_age = c_2_4_age;
        c1_income = c_2_1_income;
        c2_income = c_2_2_income;
        c3_income = c_2_3_income;
        c4_income = c_2_4_income;
        c1_score = c_2_1_score;
        c2_score = c_2_2_score;
        c3_score = c_2_3_score;
        c4_score = c_2_4_score;


        c_2_1_age = 0;
        c_2_2_age = 0;
        c_2_3_age = 0;
        c_2_4_age = 0;
        c_2_1_income = 0;
        c_2_2_income = 0;
        c_2_3_income = 0;
        c_2_4_income = 0;
        c_2_1_score = 0;
        c_2_2_score = 0;
        c_2_3_score = 0;
        c_2_4_score = 0;


        goto kmean;
    }

    /*for (int i = 0; i < x1; i++)
    {
        cout << i + 1 << "  :  ";
        for (int j = 0; j < 2; j++)
        {

            cout << k_1[i][j] << " \t";
        }
        cout << endl;
    }*/

    /* for (int i = 0; i < count; i++)
     {
         cout << " this is index storing loop" << endl;
         if (index_c1[i] == i)
         {
             center_array[i] = 1;
         }
         else if (index_c2[i] == i)
         {
             center_array[i] = 2;
         }
         else if (index_c3[i] == i)
         {
             center_array[i] = 3;

         }
         else if (index_c4[i] == i)
         {
             center_array[i] = 4;
         }
     }*/
    /*for (int i = 0; i < count; i++)
    {
        cout << i + 1 << "==";
        cout << center_array[i] << endl;
    }*/

    //string finalarray[4001][4];
   // string aa[4001];

    string** strings = new string * [201];
    for (int i = 0; i < 201; i++) {
        strings[i] = new string[6];
        for (int j = 0; j < 6; j++) {
            strings[i][j] = "";
        }
    }






    string* aa = new string[201];
    for (int i = 0; i < count; i++) {
        aa[i] = "";
    }
    /*for (int i = 0; i < 4001; i++)
    {
        for (int j = 0; j < 4;j++)
        {
            strings[i][j] = " ";
        }
    }*/
    for (int i = 0; i < count; i++)
    {
        aa[i] = to_string(center_array[i]);

    }

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (j == 5)
            {

                strings[i][j] = aa[i];
            }
            // finalarray[i][j] = to_string(center_array[i]); 
            else
            {

                strings[i][j] = array[i][j];
            }
            //cout << array[i][j] << "\t\t";

            cout << strings[i][j] << "\t\t";

        }
        cout << endl;

    }
    /*for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 3)
            {
                array[i][j] = to_string(center_array[i]);
            }
        }
    }*/
    file.close();
    /*ofstream file;
    int j = 0,y2 = 0,y3=0;
    file.open("output.txt");
    for (int i = 0; i < count;i++)
    {
        j = 0;

          file << strings[i][j] << "," << strings[i][j + 1] << "," << strings[i][j + 2] << "," << strings[i][j + 3] << endl;

    }*/


    std::ofstream outputfile;
    outputfile.open("q2_output.csv");
    string x12 = "ID",gender="gender", y = "age", z = "income", w = "score", v = "cluster";
    outputfile << x12 << ","<<gender<<"," << y << "," << z << "," << w <<"," <<v<< endl;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 6; j++) {
            outputfile << strings[i][j];
            if (j < 6 - 1) {
                outputfile << ",";
            }
        }
        outputfile << "\n";
    }

    outputfile.close();

    for (int i = 0; i < count; i++) {
        delete[] strings[i];
    }
    delete[] strings;


    delete[] aa;
    outputfile.close();
    return 0;


}