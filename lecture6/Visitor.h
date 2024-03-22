//
// Created by sigurd on 27-02-24.
//

#ifndef LECTURE6_VISITOR_H
#define LECTURE6_VISITOR_H


#include "calculator.h"

class Visitor {

public:
    virtual void visit(calculator::var_t var);
    virtual void visit(calculator::const_t con);
    virtual void visit(calculator::assign_t assign);
    virtual void visit(calculator::binary_t binary);
    virtual void visit(calculator::unary_t unary);
};


#endif //LECTURE6_VISITOR_H
