//����txt�ļ�����
//�������ݴ�����Ҫ���к˶����ݸ�ʽ���������ᵼ�³������
/*
��׼�㷨:�ɼ����Կγ�ѧ�ֲ�����ٳ���4���ٳ�����ѧ����100֮��
�ķ����㷨���ĸ��ȼ���ѧ�֡�������Լ���
�����㷨�������аٶ�
����С���㷨������ת���ɼ���ʱ����С��
*/
//by LR��2015-07-19
#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <fstream>
using namespace std;
int c1,c2=0;
double  divisor,dividend1,dividend2,dividend3,dividend4=0;
double t1,t2,t3,t4=0;
int size=0;

struct subject
{
    double credit;
    double grade;
}Sx;

queue <subject> init;


void del()
{
    while(!init.empty())
    {
        init.pop();
    }
}

double change1(double k)
{
    return k;
}

double change2(double k)//�ķ����㷨ת��
{
    if(k>=90) return 4;
    if(k>=80&&k<90) return 3;
    if(k>=70&&k<80) return 2;
    if(k>=60&&k<70) return 1;
    if(k<60) return 0;
}

double change3(double k)//�����ķ����㷨ת��
{
    if(k>=90&&k<=100) return 4;
    if(k>=85&&k<90) return 3.7;
    if(k>=82&&k<85) return 3.3;
    if(k>=78&&k<82) return 3;
    if(k>=75&&k<78) return 2.7;
    if(k>=72&&k<75) return 2.3;
    if(k>=68&&k<72) return 2;
    if(k>=64&&k<68) return 1.5;
    if(k>=60&&k<64) return 1;
    if(k<60) return 0;
}

double change4(double k)//����С�����㷨ת��
{
    if(k>=60)
        return double(k)/double(10)-double(5);
    else return double(0);
}

void add()
{
    int flag=0;
    ifstream source_file("d://source.txt");//�����滻�����ļ����ļ���ʽΪÿ����������
    if(!source_file)
    {
        cout<<"���ļ�ʧ��!���ֶ�д������:"<<endl;
        flag=1;
    }
    do
    {
        source_file>>Sx.grade>>Sx.credit;
        init.push(Sx);
    }
    while(!source_file.eof());

    if(flag==1)
    {
        cout<<"�ɼ���ǰ��ѧ���ں�"<<endl;
        while(cin>>Sx.grade&&Sx.grade>0)
    {
        cin>>Sx.credit;
        init.push(Sx);
    }
    }

}


void cal()
{
     //ofstream out_file("d://out.txt");�о�����Ҫ�������ɾ����
    int size=init.size();
    dividend1=0;
    dividend2=0;
    dividend3=0;
    dividend4=0;//������;�����
    divisor=0;//�����������
    t1=0;t2=0;t3=0;t3=0;
    for(int i=1;i<=size;i++)
    {
        subject a=init.front();
        init.pop();
        divisor+=a.credit;
        t1=a.credit*change1(a.grade);
        t2=a.credit*change2(a.grade);
        t3=a.credit*change3(a.grade);
        t4=a.credit*change4(a.grade);
        dividend1+=t1;
        dividend2+=t2;
        dividend3+=t3;
        dividend4+=t4;
    }

    double result1=double(dividend1)*double(4)/double(divisor*100);//��׼�㷨
    cout<<"���ñ�׼�㷨:";
    printf("%.2f\n",result1);
    double result2=double(dividend2)/double(divisor);
    cout<<"���ñ�׼�ķ����㷨��";
    printf("%.2f\n",result2);
    double result3=double(dividend3)/double(divisor);
    cout<<"���ñ����ķ����㷨��";
    printf("%.2f\n",result3);
    double result4=double(dividend4)/double(divisor);
    cout<<"���ñ���С���㷨��";
    printf("%.2f\n",result4);
}

int ui()
{
    cout<<endl<<
    "\t\tGPA������ (by LR)"<<endl<<
    "\t\t1.�����Ŀ"<<endl
    <<"\t\t2.����"<<endl
    <<"\t\t3.����"<<endl;
    cin>>c1;
    return c1;
}
int main()
{
    c1=0;
    while(!init.empty())
    {
        init.pop();
    }
    while(1)
    {
        switch(ui())//with no error fuction
        {
        case 1:add();break;
        case 2:del();break;
        case 3:cal();break;
        default:break;
        }
    }
    return 0;
}
