#include <iostream>

#include<iomanip>
#include <string>

using namespace std;
class Payroll
{

    public:
        float Get_gross_pay();
        float Get_gross_pay(float hours,float rate);
        float Get_PAYE(char PAYE_status);
        float Get_USC(float gross_pay);
        float Get_PRSI();
        float Get_Netpay();
        void Set_name(string n);
        void Print_payslip(int emp_no,int week);


    private:
        float dm_PAYE;
        int dm_Week_no;
        float dm_hours;
        float dm_rate;
        float dm_gross;
        string dm_PAYE_status;
        float dm_SRCOP;
        float dm_USC ;
        float dm_PRSI;
        float dm_net_pay;
        float dm_tax_credit;
        int dm_emp_no;
        string dm_name;
};
float Payroll::Get_gross_pay(){
cout<<"Enter Hours Worked:";
cin>>dm_hours;

cout<<"Enter Hourly Rate:";
cin>>dm_rate;

if(dm_rate<13.50){
    cout<<"Hourly rate must be at least €13.50-setting to €13.50.\n";
    dm_rate=13.50;
}
double convertedRate=(double) dm_rate;
cout<<"Converted rate to double="<<convertedRate<<endl;
dm_gross=dm_hours*dm_rate;
return dm_gross;



    }
    float Payroll::Get_PAYE(char PAYE_status){
        if(PAYE_status=='S'){
            dm_SRCOP=846.15;
            dm_tax_credit=38.46;
        }
        else if(PAYE_status=='C'){
            dm_SRCOP=1019.23;
            dm_tax_credit=72.11;
        }
        if(dm_gross<=dm_SRCOP){
            dm_PAYE=dm_gross*0.20;
        }else{
            dm_PAYE = (dm_SRCOP*0.20) + ((dm_gross -dm_SRCOP)* 0.40);
        }
            dm_PAYE-=dm_tax_credit;
            if(dm_PAYE<0)
                dm_PAYE=0;
            return dm_PAYE;
        }


    float Payroll::Get_USC(float gross_pay){
        dm_USC=0;
        if(gross_pay<=231){
            dm_USC=gross_pay*0.005;

        }else if(gross_pay>231&&gross_pay<=495.38){
            dm_USC=(gross_pay-231)*0.02+1.155;

        }else if(gross_pay>495.38&&gross_pay<=1347.00){
            dm_USC=((gross_pay-495.38)*0.03)+1.155+5.287;

        }else{
            dm_USC=(gross_pay-1347)*0.08+1.155+5.287+25.54;
        }
        return dm_USC;
    }
}
    float Payroll::Get_PRSI(){
    dm_PRSI=dm_gross*0.04;
    return dm_PRSI;
    }
    float Payroll::Get_Netpay()
    {
         dm_net_pay= dm_gross-(dm_PAYE+ dm_USC+dm_PRSI);

            return dm_net_pay;

        }


        void Payroll::Set_name(string n){
        dm_name=n;
        }
        void Payroll::Print_payslip(int emp_no,int week){
            dm_emp_no=emp_no;
            dm_Week_no=week;
            cout<<"----------------------------------"<<endl;
            cout<<"|"<<setw(33)<<"Rathmines IT Services"<<setw(8)<<"|"<<endl;
            cout<<"|Week No:"<<setw(29)<<dm_Week_no<<"|"<<endl;
            cout<<"|Employee No:"<<setw(25)<<dm_emp_no<<"|"<<endl;
            cout<<"|Name:"<<setw(32)<<dm_name<<"|"<<endl;
            cout<<"|----------------------------------|"<<endl;
            cout<<fixed<<setprecision(2);
            cout<<"|Gross Pay:"<<setw(26)<<dm_gross<<"|"<<endl;
            cout<<"|PAYE:"<<setw(26)<<dm_PAYE<<"|"<<endl;
            cout<<"-----------------------------------"<<endl;
            cout<<"|USC: "<<setw(26)<<dm_USC <<"|"<<endl;
            cout<<"|PRSI:"<<setw(26)<<dm_PRSI<<"|"<<endl;
            cout<<"|Net PAY:"<<setw(26)<<dm_net_pay<<"|"<<endl;
            cout<<"-------------------------------------"<<endl;

        }


int main()
{

    Payroll Emp_101;
    Emp_101.Set_name("Kim Bloggs");
    Emp_101.Get_USC(Emp_101.Get_gross_pay());
    Emp_101.Get_PAYE('S');
    Emp_101.Get_PRSI();
    Emp_101.Get_Netpay();
    Emp_101.Print_payslip(101,48);
    cout<<endl;
    Payroll Emp_102;
    Emp_102.Set_name("Joe Bloggs");
    Emp_102.Get_USC(Emp_102.Get_gross_pay());
    Emp_102.Get_PRSI();
    Emp_102.Get_PAYE('S');
    Emp_102.Get_Netpay();
    Emp_102.Print_payslip(101,48);
    cout<<endl;



    return 0;
}
}
}
