#include<iostream> //iostream.h is not supported in gcc compiler. 2nd line is mandatory for cin and cout. clrscr won't work in gcc
using namespace std;
#include <bits/stdc++.h>
//It is basically a header file that includes every standard library. In programming contests, using this file is a good idea,
// when you want to reduce the time wasted in doing chores; especially when your rank is time sensitive. In this program it is used
//for the custom sizeof
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int id[]={1,3,5,7,9,11,13,15}; // We need to update the voter ids before hand. This can't be dynamic
int size = *(&id + 1) - id;
std::vector< int > a;
class candidate
{
    public:
    char name[30];
    char partyname[30];
    int id; int count;
    candidate()
    {
    count=0;
    }
    void getdata();
    void putdata();
};
void candidate::getdata()
{
    cout<<"\nEnter Candidate Name : ";
    cin>>name;
    cout<<"\nEnter party Name : ";
    cin>>partyname;
    cout<<"\nEnter nomination ID : ";
    cin>>id;
}
void candidate::putdata()
{
    cout<<"\n"<<name<<"\t\t"<<partyname<<"\t\t"<<id<<"\n";
}
class voter
{
    public:
    char name[30];
    int voterid;
    int age;
    void getdata();
    int validate();

};
void voter:: getdata()
{
    cout<<"\nEnter name of the voter : ";
    cin>>name;
    cout<<"\nEnter your age ";
    cin>>age;
    if(age<18)
    {
    cout<<"\nYou have provided wrong date of birth Please re-enter";
    fflush(stdin);
    getdata();
    }
    cout<<"\nEnter voter id ";
    fflush(stdin);
    cin>>voterid;
}
int voter::validate()
{
    int count=0;
    /* Code to check if same voter is voting again(If one voter id is entered multiple times
    if (a.size()==0){
       a.push_back(voterid);
    }
    else{
        if (std::find(a.begin(), a.end(),voterid)==a.end()){
                a.push_back(voterid);
        }
        else
        {
            cout<<"The person has already voted";
            cout<<"why?";
            return 1;
            //for (int j = 0; j < (int)a.size(); j++) //displaying all elements of vector
            //cout<< a.at(j) <<endl;

        }
    }*/

    for(int i=0;i<size;i++){
    if(voterid==id[i])
    count++;
    }
   if(age<18||count==0)//if age<18 and if entered voterid is not present in the voter list
    {
        cout<<"\nThe candidate doesn't have right to vote: ";
        return 1;
    }
    if(count==1)
    return 2;
    else
    return 0;
}

voter v[15];candidate c[10];
void readparties()
{
    for(int i=0;i<3;i++)
    {
        printf("\nEnter details of candidate %d ", i+1);
        c[i].getdata();
        for(int j=i-1;j>=0;j--)
        {
            if(!(strcmp(c[j].name,c[i].name))||!(strcmp(c[j].partyname,c[i].partyname))||c[i].id==c[j].id)
            {
            printf("\nOne/all of the details you've provided is/are already registered by another candidate.. Check and try again.. ");
            i--;
            }
        }
    }

}
void voterdetails()
{
    int flag,index=0,vote,i=0;
    char voter;
    void putcandidates();
    while(i<size)
    {
        printf("Do you want to vote(Y/y)?");
        cin>>voter;
        if(voter !='y'&&voter!='Y')
            {
                break;
            }
		flag=0;
		// clrscr();
		printf("\nEnter %d voter details \n",i+1);
		v[i].getdata();
        if(v[i].validate()==1)
        {
			printf("\nPress Enter to Re-enter the details");
			i++;
			getch();
			flag=1;
        }
        else if(v[i].validate()==0)
        {
            printf("\nVoter is not registered.. \nPress enter to give ID correctly \n");
            i++;
            getch();
            flag=1;

        }

		if(flag==1)
		{
			i--;flag=0;
			continue;
		}
		else
		{
			putcandidates();
			for(int j=0;j<3;j++)
			{
				c[j].putdata();
			}
			printf("\nEnter the id of the candidate to vote for him :  ");
			scanf("%d",&vote);
            for(int k=0;k<3;k++)
				{
					//cout<<"\n"<<c[k].id;
					if(vote==c[k].id)
					{
						index=1;
						c[k].count++;
						//cout<<"\n"<<c[k].count;
						break;
					}
				}
			if(index==0)
				{
					printf("\nYou have entered wrong id Re-try : ");
					i--;
				}
            else
                printf("Voted successfully.\nPlease move to next cabin to collect your receipt\n\n\n\n\n");
		}
		i++;
    }

}
void putcandidates()
{
    cout<<"\nName \t\t  Partyname  \t\t ID   \n";
}
void counting()
{
    int max=0,maxindex;
    for(int i=0;i<3;i++)
    {
        if(c[i].count>max)
        {
            max=c[i].count;
            maxindex=i;
        }

    }
//    clrscr();
    cout<<"\n\nResults of the election \n";
    cout<<"\nWinner is  "<<c[maxindex].name<<" of party "<<c[maxindex].partyname<<"  with votes  "<<max;
}
int main(void)
{
    int op;
    do
    {
//    	clrscr();
		printf("\n\t\t------------------------------------------------\n");
		printf("\t\t|             WELCOME TO ELECTIONS 2K14       |\n ");
		printf("\t\t------------------------------------------------\n");
		//cout << "Number of elements in arr[] is "<< size;
		printf("\n1.Nominations\n2.Voter\n3.Counting\n4.Exit\nEnter choice : ");
		scanf("%d",&op);
		if(op==1)
		{
			readparties();
		}
		else if(op==2)
		{
			voterdetails();
		}
		else if(op==3)
		{
			counting();
			cout<<"\n\n\n\n-----------Presented by--------------";
			cout<<"\n\n\n\n-----------G.Jashwanth         (1602-12-737-011)\n\n N.Manideep Reddy       (1602-12-737-015)\n\n\n Thank You.......\n";
			getch();
		}
    }
	while(op!=4);
}
