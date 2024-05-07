#include <iostream>

using namespace std;

void MenuTask()
{
    cout << "    Menu Task\n";
    cout << "    1.  Task 1\n";
    cout << "    2.  Task 2\n";
    cout << "    3.  Exit\n";
}

class VectorInt
{
private:
    int* data;
    int size;
    int value;
    int codeError;
    static int objectCount;

public:
    //конструктор без параметрів
    VectorInt() : size(1), codeError(0)
    {
        objectCount++;
        data = new int[size];
        if (data == nullptr)
        {
            codeError = OUT_OF_MEMORY;
            return;
        }
        data[0] = 0;
    }

    //коструктор з одним параметром
    VectorInt(int s) : size(s), value(0), codeError(NONE)
    {
        objectCount++;
        data = new int[s];
        if (data == nullptr)
        {
            codeError = OUT_OF_MEMORY;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            data[i] = value;
        }
    }

    //конструктор із двома параметрами
    VectorInt(int s, int initValue) : size(s), value(value), codeError(NONE)
    {
        objectCount++;
        data = new int[s];
        if (data == nullptr)
        {
            codeError = OUT_OF_MEMORY;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            data[i] = initValue;
        }
    }

    //конструктор копіювання
    VectorInt(const VectorInt& other) : size(other.size), codeError(NONE)
    {
        objectCount++;
        size = other.size;
        data = new int[size];
        if (data == nullptr)
        {
            codeError = OUT_OF_MEMORY;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    //деструктор
    ~VectorInt()
    {
        objectCount--;
        delete[] data;
    }

    //функція унарного префіксних та постфіксних ++ та --
    VectorInt& operator++()
    {
        for (int i = 0; i < size; i++)
        {
            ++data[i];
        }
        return *this;
    }
    
    VectorInt operator++(int)
    {
        VectorInt temp(*this);
        operator++();
        return temp;
    }

    VectorInt& operator--()
    {
        for (int i = 0; i < size; i++)
        {
            --data[i];
        }
        return *this;
    }

    VectorInt operator--(int)
    {
        VectorInt temp(*this);
        operator--();
        return temp;
    }

    //операція унітарного логічного заперечення
    bool operator!()
    {
        return size != 0;
    }

    //операція унітарного побітового заперечення
    VectorInt operator~()
    {
        VectorInt result(*this);
        for (int i = 0; i < size; i++)
        {
            result.data[i] = ~result.data[i];
        }
        return result;
    }

    //операція унітарного арифметичного "-" (віднімання)
    VectorInt operator-()
    {
        VectorInt result(*this);
        for (int i = 0; i < size; i++)
        {
            result.data[i] = -result.data[i];
        }
        return result;
    }

    //операція присвоєння =:
    VectorInt& operator=(const VectorInt& other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // += - додавання векторів
    VectorInt& operator+=(const VectorInt& other)
    {
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                data[i] += other.data[i];
            }
        }
        return *this;
    }

    // -= - віднімання векторів
    VectorInt& operator-=(const VectorInt& other)
    {
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                data[i] -= other.data[i];
            }
        }
        return *this;
    }

    // *= - множення, вектора на число
    VectorInt& operator*=(int scalar)
    {
        for (int i = 0; i < size; i++)
        {
            data[i] *= scalar;
        }
        return *this;
    }

    // /= - ділення, вектора на число
    VectorInt& operator/=(int scalar)
    {
        if (scalar != 0)
        {
            for (int i = 0; i < size; i++)
            {
                data[i] /= scalar;
            }
        }
        return *this;
    }

    // %= - остача від ділення, вектора на число
    VectorInt& operator%=(int scalar)
    {
        if (scalar != 0)
        {
            for (int i = 0; i < size; i++)
            {
                data[i] %= scalar;
            }
        }
        return *this;
    }

    // |= - побітове додаванням векторів
    VectorInt& operator|=(const VectorInt& other)
    {
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                data[i] |= other.data[i];
            }
        }
        return *this;
    }

    // ^= - побітове додавання за модулем 2 векторів
    VectorInt& operator^=(const VectorInt& other)
    {
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                data[i] ^= other.data[i];
            }
        }
        return *this;
    }

    // &= - побітове по-елементне множення векторів
    VectorInt& operator&=(const VectorInt& other)
    {
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                data[i] &= other.data[i];
            }
        }
        return *this;
    }

    //арифметичні бінарні
    
    // + - додавання векторів
    VectorInt operator+(const VectorInt& other) const
    {
        VectorInt result(*this);
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                result.data[i] += other.data[i];
            }
        }
        return result;
    }

    // – - віднімання векторів
    VectorInt operator-(const VectorInt& other) const
    {
        VectorInt result(*this);
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                result.data[i] -= other.data[i];
            }
        }
        return result;
    }

    // * - множення, вектора на число
    VectorInt operator*(const VectorInt& other) const
    {
        VectorInt result(*this);
        for (int i = 0; i < size; i++)
        {
            result.data[i] *= other.data[i];
        }
        return result;
    }

    // / - ділення, вектора на число типу
    VectorInt operator/(const VectorInt& other) const
    {
        VectorInt result(*this);
        if (other.data != 0)
        {
            for (int i = 0; i < size; i++)
            {
                result.data[i] /= other.data[i];
            }
        }
        return result;
    }

    // % - остача від ділення, вектора на число типу
    VectorInt operator%(int scalar) const
    {
        VectorInt result(*this);
        if (scalar != 0)
        {
            for (int i = 0; i < size; i++)
            {
                result.data[i] %= scalar;
            }
        }
        return result;
    }

    // | - побітове додавання векторів
    VectorInt operator|(const VectorInt& other) const
    {
        VectorInt result(*this);
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                result.data[i] |= other.data[i];
            }
        }
        return result;
    }

    // ^ - побітове додавання за модулем 2 векторів
    VectorInt operator^(const VectorInt& other) const
    {
        VectorInt result(*this);
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                result.data[i] ^= other.data[i];
            }
        }
        return result;
    }

    // & - побітове по-елементне множення векторів
    VectorInt operator&(const VectorInt& other) const
    {
        VectorInt result(*this);
        if (size == other.size)
        {
            for (int i = 0; i < size; i++)
            {
                result.data[i] &= other.data[i];
            }
        }
        return result;
    }

    //побітові операції зсувів

    //функція введення >> (побітовий зсув право) 
    friend VectorInt operator>>(istream& is, VectorInt& vec)
    {
        for (int i = 0; i < vec.size; i++)
        {
            is >> vec.data[i];
        }
        return vec;
    }

    //функція введення << (побітовий зсув ліво)
    friend ostream& operator<<(ostream& os, const VectorInt& vec)
    {
        for (int i = 0; i < vec.size; i++)
        {
            os << vec.data[i] << " ";
        }
        return os;
    }

    VectorInt operator<<(int shift) const
    {
        VectorInt result(*this);
        for (int i = 0; i < size; i++)
        {
            result.data[i] <<= shift;
        }
        return result;
    }

    VectorInt operator>>(int shift) const
    {
        VectorInt result(*this);
        for (int i = 0; i < size; i++)
        {
            result.data[i] >>= shift;
        }
        return result;
    }

    //функція рівності ==
    bool operator==(const VectorInt& other) const
    {
        if (size != other.size)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (data[i] != other.data[i])
            {
                return false;
            }
        }
        return true;
    }

    //функція нерівності!=
    bool operator!=(const VectorInt& other) const
    {
        return !(*this == other);
    }

    //операція індексації []
    int& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            codeError = INDEX_OUT_OF_RANGE;
            return data[0];
        }
        return data[index];
    }

    //функція розподілу пам’яті
    void allocateMemory(int s)
    {
        size = s;
        data = new int[size];
    }

    //функція звільнення пам'яті
    void freeMemory()
    {
        delete[] data;
        size = 0;
    }

    void operator()()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // > (більше) для двох векторів
    bool operator>(const VectorInt& other) const
    {
        if (size != other.size)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (data[i] <= other.data[i])
            {
                return false;
            }
        }
        return true;
    }

    // >= (більше рівне) для двох векторів
    bool operator>=(const VectorInt& other) const
    {
        if (size != other.size)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (data[i] < other.data[i])
            {
                return false;
            }
        }
        return true;
    }

    // < (менше) для двох векторів
    bool operator<(const VectorInt& other) const
    {
        if (size != other.size)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (data[i] >= other.data[i])
            {
                return false;
            }
        }
        return true;
    }

    // <=(менше рівне) для двох векторів
    bool operator<=(const VectorInt& other) const
    {
        if (size != other.size)
        {
            return false;
        }
        for (int i = 0; i < size; i++)
        {
            if (data[i] > other.data[i])
            {
                return false;
            }
        }
        return true;
    }

    // виклику функції ()
    void Output()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "v [ " << i << " ] " << data[i] << endl;
        }
        cout << endl;
    }

    // виведення помилки
    enum ErrorCodes
    {
        NONE = 0,
        OUT_OF_MEMORY,
        INDEX_OUT_OF_RANGE
    };

    //функція підрахунку числа об'єктів
    static int ObjectCount()
    {
        return objectCount;
    }

    // введення данних
    void ConsoleInput()
    {
        cout << "Size ";
        cin >> size;
        delete[] data;
        data = new int[size];
        cout << "Elements ";
        for (int i = 0; i < size; i++)
        {
            cin >> data[i];
        }
    }
};

class Associative
{
    struct Node
    {
        string num;
        string propus;
        Node* next;

        // Конструктор з параметрами
        Node(const string& n, const string& p) : num(n), propus(p), next(nullptr) {}
    };

    Node* head;
    int errorCode;

public:
    enum ErrorCodes
    {
        NONE = 0,
        NUMBER_NOT_FOUND
    };

    //конструктор без параметрів
    Associative() : head(nullptr), errorCode(NONE) {}

    //деструктор
    ~Associative()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    //функція створення пари зв'язаних даних
    void createAssociations(const string& num, const string& propus)
    {
        Node* newNode = new Node(num, propus);
        newNode->next = head;
        head = newNode;
    }

    //оператор отримання прописного числа 
    string operator[](const string& num)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->num == num)
            {
                errorCode = NONE;
                return current->propus;
            }
            current = current->next;
        }
        errorCode = NUMBER_NOT_FOUND;
    }

    //оператор пошуку
    string operator()(const string& num)
    {
        return (*this)[num];
    }

    int getErrorCode() const
    {
        return errorCode;
    }

    //функція друку
    friend ostream& operator<<(ostream& os, const Associative& assoc)
    {
        Node* current = assoc.head;
        while (current != nullptr)
        {
            os << current->num << ": " << current->propus << endl;
            current = current->next;
        }
        return os;
    }

    //функція введення
    friend istream& operator>>(istream& is, Associative& assoc)
    {
        string num, propus;
        while (true)
        {
            cout << "num and propusne num (q to quit) ";
            is >> num;
            if (num == "q")
                break;
            is >> propus;
            assoc.createAssociations(num, propus);
        }
        return is;
    }
};

int VectorInt::objectCount = 0;

int main()
{
    MenuTask();

    int choice;

    do
    {
        cout << "Task: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Task 1
        {
            VectorInt v1;
            VectorInt v2;

            cout << "Vector 1" << endl;
            v1.ConsoleInput();
            cout << "Vector 2" << endl;
            v2.ConsoleInput();
            cout << endl;

            cout << "v1" << endl;
            v1.Output();
            cout << "v2" << endl;
            v2.Output();

            VectorInt vdodat = v1 + v2;
            VectorInt vminus = v1 - v2;

            cout << "v1 += v2" << endl;
            vdodat.Output();
            cout << "v1 -= v2" << endl;
            vminus.Output();

            cout << "v1 == v2 = " << (v1 == v2) << endl;
            cout << "v1 != v2 = " << (v1 != v2) << endl;
            cout << "v1 > v2 = " << (v1 > v2) << endl;
            cout << "v1 <= v2 = " << (v1 <= v2) << endl;
            cout << endl;

            VectorInt vmnoj = v1 * v2;
            VectorInt vdil = v1 / v2;

            cout << "v1 * v2" << endl;
            vmnoj.Output();
            cout << "v1 / v2" << endl;
            vdil.Output();

            VectorInt v_pob_dod_2 = v1 ^ v2;
            VectorInt v_pob_dod = v1 | v2;

            cout << "v1 ^ v2" << endl;
            v_pob_dod_2.Output();
            cout << "v1 | v2" << endl;
            v_pob_dod.Output();

            cout << "Object count = " << VectorInt::ObjectCount() << endl;

            choice = 3;
            break;
        }
        case 2: // Task 2
        {
            Associative numbers;

            cin >> numbers;
            cout << endl;

            cout << "Task 2 " << endl;
            cout << numbers;

            string poshuknum;
            cout << "Number dlia poshuku propusnogo number ";
            cin >> poshuknum;

            string propusNumber = numbers[poshuknum];
            if (numbers.getErrorCode() == Associative::NUMBER_NOT_FOUND)
            {
                cout << "Number not found" << endl;
            }
            else
            {
                cout << poshuknum << ": " << propusNumber << endl;
            }
            choice = 3;
            break;
        }
        case 3: // Exit
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (choice != 3);

    return 0;
}