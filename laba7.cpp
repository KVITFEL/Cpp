#include <cassert> // assert
#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>
#include <fstream>
using namespace std;
//Для того чтобы избежать утечек памяти в базовом классе Expression,
//необходимо определить виртуальный деструктор в базовом классе Expression
struct Expression {
    virtual ~Expression() {}
    virtual double evaluate() const = 0;// можно сделать виртуальным метод evaluate() в базовом классе/
};

struct Number : Expression {
    Number(double value) : value_(value) {}
    double value() const { return value_; }
    double evaluate() const override { return value_; }
private:
    double value_;
};

struct BinaryOperation : Expression {
    enum {
        PLUS = '+',
        MINUS = '-',
        DIV = '/',
        MUL = '*'
    };
    BinaryOperation(Expression const *left, int op, Expression const *right) : left_(left), op_(op), right_(right) {
        assert(left_ && right_);
    }
    ~BinaryOperation() {
        delete left_;
        delete right_;
    }
    Expression const *left() const { return left_; }
    Expression const *right() const { return right_; }
    int operation() const { return op_; }

    double evaluate() const override {
        double left = left_->evaluate();
        double right = right_->evaluate();
        switch (op_) {
        case PLUS: return left + right;
        case MINUS: return left - right;
        case DIV: return left / right;
        case MUL: return left * right;
        }
        assert(0);
        return 0.0;
    }
private:
    Expression const *left_;
    Expression const *right_;
    int op_;
};

int main() {
    Expression *e1 = new Number(1.234);
    Expression *e2 = new Number(-1.234);
    Expression *e3 = new BinaryOperation(e1, BinaryOperation::DIV, e2);

    cout << e3->evaluate() << endl;

    delete e3;
    delete e2;
    delete e1;

    return 0;
}


----------------------------------------------------------
#include <cassert> // assert
#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>
#include <fstream>
using namespace std;
struct Expression {
    virtual ~Expression() {}
    virtual double evaluate() const = 0;
};

struct Number : Expression {
    Number(double value) : value_(value) {}
    double value() const { return value_; }
    double evaluate() const { return value_; }
private:
    double value_;
};

struct BinaryOperation : Expression {
    enum {
        PLUS = '+',
        MINUS = '-',
        DIV = '/',
        MUL = '*'
    };
    BinaryOperation(Expression const* left, int op, Expression const* right)
        : left_(left), op_(op), right_(right) {
        assert(left_ && right_);
    }
    ~BinaryOperation() {
        delete left_;
        delete right_;
    }
    Expression const* left() const { return left_; }
    Expression const* right() const { return right_; }
    int operation() const { return op_; }
    double evaluate() const {
        double left = left_->evaluate();
        double right = right_->evaluate();
        switch (op_) {
        case PLUS: return left + right;
        case MINUS: return left - right;
        case DIV: return left / right;
        case MUL: return left * right;
        }
        assert(0);
        return 0.0;
    }
private:
    Expression const* left_;
    Expression const* right_;
    int op_;
};

struct FunctionCall : Expression {
    FunctionCall(std::string const& name, Expression const* arg) : name_(name), arg_(arg) {
        assert(arg_);
    }
    ~FunctionCall() { delete arg_; }
    double evaluate() const {
        double argValue = arg_->evaluate();
        if (name_ == "sqrt") {
            return std::sqrt(argValue);
        }
        else if (name_ == "abs") {
            return std::fabs(argValue);
        }
        else {
            assert(0);
            return 0.0;
        }
    }
    std::string const& name() const { return name_; }
    Expression const* arg() const { return arg_; }
private:
    std::string name_;
    Expression const* arg_;
};

int main() {


    Expression* n32 = new Number(32.0);
    Expression* n16 = new Number(16.0);
    Expression* minus = new BinaryOperation(n32, '-', n16);
    Expression* callSqrt = new FunctionCall("sqrt", minus);
    Expression* n2 = new Number(2.0);
    Expression* mult = new BinaryOperation(n2, '*', callSqrt);
    Expression* callAbs = new FunctionCall("abs", mult);
    cout << callAbs->evaluate() << endl; // Вывод программы: 8
    delete callAbs;
    return 0;

}
