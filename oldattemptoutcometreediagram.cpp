#include <iostream>
#include <fstream>
using namespace std;


string checkValuePLayer(int valuePlayer){
    //4Att,4 ATTK, 4Def
    string attackPlayer="A";
    string defensePlayer="D";
    if (valuePlayer == 0){
        return attackPlayer;
    }
    if(valuePlayer == 1){
        return defensePlayer;
    }else if (valuePlayer ==2){
        return attackPlayer;
    }
}

string checkValueComputer(int valueComputer){
    //4 Att,4Def,4Heal
    string attackComputer ="a";
    string defenseComputer ="d";
    string healComputer="h";
    
    if (valueComputer ==0){
        return attackComputer;
    }else if(valueComputer == 1){
        return defenseComputer;
    }
    else{
        return healComputer;
    }
}

int main(){
    ofstream outfile;
    int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,count;
    string p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;

    outfile.open("possibility.txt");

    for(a=0;a<1;a++){
        p1 = "L";//A D
        for(b=0;b<1;b++){
            cout<<"On Second Loop :"<<b<<endl;
            c1 = "K";//a d h
            for(c=0;c<3;c++){
                cout<<"On Third Loop :"<<c<<endl;
                p2 = checkValuePLayer(c);//A D
                for(d=0;d<3;d++){
                    cout<<"On Fourth Loop :"<<d<<endl;
                    c2 = checkValueComputer(d);//a d h
                    for(e=0;e<3;e++){
                        cout<<"On Fifth Loop :"<<e<<endl;
                        p3= checkValuePLayer(e);//A D
                        for(f=0;f<3;f++){
                            cout<<"On Sixth Loop :"<<f<<endl;
                            c3 = checkValueComputer(f);
                            for(g=0;g<3;g++){
                                p4 = checkValuePLayer(g);
                                for(h=0;h<3;h++){
                                    c4 = checkValueComputer(h);
                                    for(i=0;i<3;i++){
                                        p5 = checkValuePLayer(i);
                                        for(j=0;j<3;j++){
                                            c5 = checkValueComputer(j);
                                            for(k=0;k<3;k++){
                                                p6 = checkValuePLayer(k);
                                                for(l=0;l<3;l++){
                                                    c6 = checkValueComputer(l);
                                                    for(m=0;m<3;m++){
                                                        p7 = checkValuePLayer(m);
                                                        for(n=0;n<3;n++){
                                                            c7 = checkValueComputer(n);
                                                            for(o=0;o<3;o++){
                                                                p8 = checkValuePLayer(o);
                                                                for(p=0;p<3;p++){
                                                                    c8 = checkValueComputer(p);
                                                                    for(q=0;q<3;q++){
                                                                        p9 = checkValuePLayer(q);
                                                                        for(r=0;r<3;r++){
                                                                            c9 = checkValueComputer(r);
                                                                            for(s=0;s<3;s++){
                                                                                p10 = checkValuePLayer(s);
                                                                                for(t=0;t<3;t++){
                                                                                    c10 = checkValueComputer(t);
                                                                                    outfile<<p1<<c1<<p2<<c2<<p3<<c3<<p4<<c4<<p5<<c5<<p6<<c6<<p7<<c7<<p8<<c8<<p9<<c9<<p10<<c10<<endl;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    
                }
                
            }
            
        }
        
    }

    outfile.close();



}
