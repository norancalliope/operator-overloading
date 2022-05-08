#include <iostream>
#include <cmath>
using namespace std;

class persegiPanjang{
    private:
        float xmax, xmin, ymax, ymin;
    public:
        persegiPanjang(float titikTengahX, float titikTengahY, float panjang, float lebar);
        bool operator== (persegiPanjang const &)const;
        persegiPanjang operator+ (persegiPanjang const &);
        persegiPanjang operator- (persegiPanjang const &);
        void operator++ ();
        void operator++(int);
        void operator-- ();
        void operator--(int);
        float operator[](int pilihan);
        void output();
        
        
};
    float panjang, lebar, tx, ty;
    void input();
int main(){
    int pilihan;
    const char *index[4] = {"xmin", "xmax", "ymin", "ymax"};

    persegiPanjang pp3(0,0,0,0);


    cout << "Masukkan Data Persegi Panjang 1" << endl;
    input();
    persegiPanjang pp1(tx, ty, panjang, lebar);
    cout << "Masukkan Data Persegi Panjang 2" << endl;
    input();
    persegiPanjang pp2(tx, ty, panjang, lebar);

    system("CLS");

    while (1){
        cout << "Pilih operator yang  digunakan" << endl;
        cout << "1. OPERATOR +" << endl;
        cout << "2. OPERATOR -" << endl;
        cout << "3. OPERATOR ++" << endl;
        cout << "4. OPERATOR --" << endl;
        cout << "5. OPERATOR []" << endl;
        cout << "6. OPERATOR ==" << endl;
        cout << "7. Exit Program" << endl;
        cout << "Pilihan anda : ";
        cin >> pilihan;
        switch (pilihan){
        case 1:
            {
                system("CLS");
                cout << endl;
                cout << "Mengambil luas gabungan dari 2 persegi panjang" << endl;
                pp3 = pp1 + pp2;
                if (pp1==pp2){
                    pp3.output();
                }
                cin.get();
                system("CLS");
            }
            break;
        case 2:
            {
                system("CLS");
                cout << endl;
                cout << "Mengambil irisan 2 persegi panjang" << endl;
                pp3 = pp1 - pp2;
                if (pp1==pp2){
                    pp3.output();
                }
                cin.get();

            }
            break;
        case 3:
            {
                system("CLS");
                cout << endl;
                cout << "OPERATOR ++ (Menjadikan luas persegi panjang 2 kali lebih besar)" << endl;
                ++pp1;
                cout << "Persegi Panjang 1 setelah diberi Operator ++ : " << endl;
                pp1.output();
                --pp1;
                ++pp2;
                cout << "Persegi Panjang 2 setelah diberi Operator ++ : " << endl;
                pp2.output();
                --pp2;
                cin.get();
            }
            break;
        case 4:
            {
                system("CLS");
                cout << endl;
                cout << "OPERATOR -- (Menjadikan luas persegi panjang 2 kali lebih kecil (1/2 kali semula))" << endl;
                --pp1;
                cout << "Persegi Panjang 1 setelah diberi Operator -- : " << endl;
                pp1.output();
                ++pp1;
                --pp2;
                cout << "Persegi Panjang 2 setelah diberi Operator -- : " << endl;
                pp2.output();
                ++pp2;
                cin.get();
            }
            break;
        case 5:
            {
                system("CLS");
                cout << endl;
                cout << "OPERATOR [] (Perbandingan indeks Pp1 dan Pp2)" << endl;
                for(int pilihan = 1; pilihan < 5; pilihan++){
                    cout << "Nilai " << index[pilihan-1] << " Pp1 : " << pp1[pilihan] << endl;
                    cout << "Nilai " << index[pilihan-1] << " Pp2 : " << pp2[pilihan] << endl;
                    if (pp1[pilihan] > pp2[pilihan]){
                        cout << index[pilihan-1] << " Pp1 lebih besar dari " << index[pilihan-1] << " Pp2" << endl;
                    }else if(pp2[pilihan] > pp1[pilihan]){
                        cout << index[pilihan-1] << " Pp2 lebih besar dari " << index[pilihan-1] << " Pp1" << endl;;
                    }else{
                        cout << "Kedua " << index[pilihan-1] << " sama" << endl;
                    }
                    cout << endl<< endl;
                }
                cin.get();
                system("CLS");
            }
            break;
        case 6:
            {
                system("CLS");
                cout << endl;
                cout << "OPERATOR == (Pembuktian Kedua Persegi panjang saling beririsan/tidak)" << endl;
                if (pp1==pp2){
                    cout << "Kedua persegi panjang beririsan" << endl;
                }else{
                    cout << "Kedua persegi panjang tidak beririsan" << endl;
                }
                cin.get();
                system("CLS");
            }
            break;
        case 7:
            return 0;
        }
    }
}


void persegiPanjang::output(){
    float panjang = this->xmax - this->xmin; panjang = abs(panjang);
    float lebar   = this->ymax - this->ymin; lebar   = abs (lebar);
    
    cout << "Titik Tengah X : " << (this->xmax - this->xmin)/2 + this->xmin; cout << endl;
    cout << "Titik Tengah Y : " << (this->ymax - this->ymin)/2 + this->ymin; cout << endl;
    cout << "Panjang Sumbu X : " << panjang; cout << endl;
    cout << "Lebar Sumbu Y : " << lebar; cout << endl;
    cout << "Nilai xmin : " << this->xmin; cout << endl;
    cout << "Nilai xmax : " << this->xmax; cout << endl;
    cout << "Nilai ymin : " << this->ymin; cout << endl;
    cout << "Nilai ymax : " << this->ymax; cout << endl;
}

persegiPanjang::persegiPanjang(float titikTengahX, float titikTengahY, float panjang, float lebar){
    this->xmin = titikTengahX - (panjang/2);
    this->ymin = titikTengahY - (lebar/2);
    this->xmax = titikTengahX + (panjang/2);
    this->ymax = titikTengahY + (lebar/2);
}

bool persegiPanjang::operator==(persegiPanjang const &baru)const{
    if (this->xmax > baru.xmin && this->xmin < baru.xmax && this->ymax > baru.ymin && this->ymin < baru.ymax)
    {
        return true;
    }else
    {
        return false;
    }
}

persegiPanjang persegiPanjang::operator+(persegiPanjang const &baru){
    persegiPanjang temp(0,0,0,0);

    if (*this == baru)
    {
        temp.xmin = min(this-> xmin,baru.xmin);
        temp.ymin = min(this-> ymin,baru.ymin);
        temp.xmax = max(this-> xmax,baru.xmax);
        temp.ymax = max(this-> ymax,baru.ymax);
    }
    else
    {
        cout << "Kedua bangun tidak beririsan" << endl;
    }
    return temp;
}

persegiPanjang persegiPanjang::operator-(persegiPanjang const &baru)
{
    persegiPanjang temp(0,0,0,0);

    if (*this == baru)
    {
        temp.xmin = max(this-> xmin,baru.xmin);
        temp.ymin = max(this-> ymin,baru.ymin);
        temp.xmax = min(this-> xmax,baru.xmax);
        temp.ymax = min(this-> ymax,baru.ymax);
    }
    else
    {
        cout << "Kedua bangun tidak beririsan" << endl;
    }
    return temp;
}

void persegiPanjang::operator++()
{
    float panjang = 0, lebar = 0, titikTengahX = 0, titikTengahY = 0;

    panjang = this->xmax - this->xmin; panjang = abs(panjang);
    lebar = this->ymax - this->ymin; lebar = abs(lebar);
    titikTengahX = this->xmin + panjang/2;
    titikTengahY = this->ymin + lebar/2;

    panjang = panjang * 2;
    lebar = lebar * 2;

    this->xmin = titikTengahX - panjang/2;
    this->ymin = titikTengahY - lebar/2;
    this->xmax = titikTengahX + panjang/2;
    this->ymax = titikTengahY + lebar/2;
}

void persegiPanjang::operator--()
{
    float panjang = 0, lebar = 0, titikTengahX = 0, titikTengahY = 0;

    panjang = this->xmax - this->xmin; panjang = abs(panjang);
    lebar = this->ymax - this->ymin; lebar = abs(lebar);
    titikTengahX = this->xmin + panjang/2;
    titikTengahY = this->ymin + lebar/2;

    panjang = panjang / 2;
    lebar = lebar / 2;

    this->xmin = titikTengahX - panjang/2;
    this->ymin = titikTengahY - lebar/2;
    this->xmax = titikTengahX + panjang/2;
    this->ymax = titikTengahY + lebar/2;
}
void persegiPanjang::operator++(int){}
void persegiPanjang::operator--(int){}

float persegiPanjang::operator[](int pilihan){
    switch (pilihan){
    case 1:
        return this->xmin;
        break;
    case 2:
        return this->xmax;
        break;
    case 3:
        return this->ymin;
        break;
    case 4:
        return this->ymax;
        break;
    }
    return 0;
}

void input(){
    cout << "Panjang Sumbu X : "; cin >> panjang; cout << endl;
    cout << "Lebar Sumbu Y : "; cin >> lebar; cout << endl;
    cout << "Titik Tengah X : "; cin >> tx; cout << endl;
    cout << "Titik Tengah Y : "; cin >> ty; cout << endl;
}