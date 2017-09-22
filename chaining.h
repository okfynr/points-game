#ifndef CHAINING_H
#define CHAINING_H

#include <QMainWindow>
#include <QWidget>
#include <QThread>
#include <vector>

using std::vector;

typedef QVector<int>  sending_type;
//qRegisterMetaType<sending_type>("sending_type");

class Chaining : public QThread
{
    Q_OBJECT

public:
    Chaining(double, double, int, QObject*);
    ~Chaining();

signals:
    void newChain(sending_type);
//    void notfinish(bool state);
protected:
     void run();

private:
    double xDot, yDot;
    int Step;

    int add_cycle(int, int);
    void dfs(int);
    //int true_cycle(vector<vector<int> > &, int);

};


#endif // CHAINING_H