/*
LANG: C
TASK: PLATE
AUTHOR: Tapat Toungsakul
CENTER: Home
*/
#include <stdio.h>
int main()
{
    struct Data 
    {
        int room;
        int id;
    };
    int c,s,i,j;
    scanf("%d %d", &c, &s);
    struct Data student[s], line[s];
    int exit[s], count1 = 0, count2 = 0;
    for (i = 0; i < s; i ++) 
    {
        scanf("%d %d", &student[i].room, &student[i].id);
        line[i].id = line[i].room = 0;
    }
    char cmd;
    while (cmd != 'X')
    {
        scanf("%c", &cmd);
        if (cmd == 'E') 
        {
            int id, room;
            scanf("%d", &id);
            for (i=0;i<s; i++)
            {
                if (student[i].id == id)
                {
                    room = student[i].room;
                    break;
                }
            }
            if (count1 == 0)
            {
                count1 ++;
                line[0].id = id;
                line[0].room = room;
            } 
            else
            {
                int alr = 0;
                for (i = 0; i < count1; i ++)
                {
                    if (line[i].room == room && line[i + 1].room != room)
                    {
                        for (j = count1; j > i; j --)
                        {
                            line[j].room = line[j - 1].room;
                            line[j].id = line[j - 1].id;
                        }
                        line[i + 1].room = room;
                        line[i + 1].id = id;
                        count1 ++;
                        alr ++;
                        break;
                    }
                }
                if (alr == 0)
                {
                    line[count1].room = room;
                    line[count1].id = id;
                    count1 ++;
                }
            }
        }
        else if (cmd == 'D')
        {
            exit[count2] = line[0].id;
            for (i = 0; i < count1; i ++)
            {
                line[i].room = line[i + 1].room;
                line[i].id = line[i + 1].id;
            }
            line[count1 - 1].room = line[count1 - 1].id = 0;
            count1 --;
            count2 ++;
        }
    }
    for (i = 0; i < count2; i ++) 
    {
        printf("%d\n", exit[i]);
    }
    if(count2 == 0)
    {
        printf("empty");
    }
    else if(count2 != 0)
    {
        printf("0");
    }
    return 0;
}