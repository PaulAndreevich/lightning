#ifndef LINE_H
#define LINE_H

class Line
{
private:
    int line_begin;
    int line_end;
public:
    Line() : line_begin(0), line_end(0) {}

    Line(int begin, int end) {line_begin = begin; line_end = end;}

    void setLine(int begin, int end) {line_begin = begin; line_end = end;}

    int getBegin() const {return line_begin;}

    int getEnd() const {return line_end;}
};

#endif // LINE_H
