/**
 * WARNING: DEMO CREEVE CODE, WILL NOT COMPILE
 *
 */
namespace MySpace
{
    class Cls
    {
        int member;
        // more stuff
        constructor ()
        {
            // code
        }
        constructor (int x)
        {
            this.member = x;
            // code
        }
        destructor ()
        {
            // code
        }
        int foo ()
        {
            this.member = 5;
            this.bar ();
            return 0;
        }
        void bar ()
        {
            // code
        }
    }
}

int main()
{
    MySpace::Cls cl1 = new MySpace::Cls ();
    int x = cl1.foo ();

    // without new
    MySpace::Cls cl1 = MySpace::Cls ();
}

// -----------------------------------------

// Compilation Result:

# include <stdio.h>
# include <stdlib.h>

typedef struct MySpace_Cls
{
    int member;
    // more stuff
} MySpace_Cls;

void MySpace_Cls_default_constructor (MySpace_Cls *this_ptr);
void MySpace_Cls_param_constructor (MySpace_Cls *this_ptr, int x);
void MySpace_Cls_destructor (MySpace_Cls *this_ptr);
int MySpace_Cls_foo (MySpace_Cls *this_ptr);
void MySpace_Cls_bar (MySpace_Cls *this_ptr);

void MySpace_Cls_default_constructor (MySpace_Cls *this_ptr)
{
    if (this_ptr == NULL) {
        abort();
    }
    MySpace_Cls this = *this_ptr;
    // code
}

void MySpace_Cls_param_constructor (MySpace_Cls *this_ptr, int x)
{
    if (this_ptr == NULL) {
        abort();
    }
    MySpace_Cls this = *this_ptr;
    // code ↓
    this.member = x;
}

void MySpace_Cls_destructor (MySpace_Cls *this_ptr)
{
    if (this_ptr == NULL) {
        abort();
    }
    MySpace_Cls this = *this_ptr;
    // code
    free (this_ptr);
}

int MySpace_Cls_foo (MySpace_Cls *this_ptr)
{
    if (this_ptr == NULL) {
        abort();
    }
    MySpace_Cls this = *this_ptr;
    // code ↓
    this.member = 5;
    MySpace_Cls_bar (&this);
    return 0;
}

void MySpace_Cls_bar (MySpace_Cls *this_ptr)
{
    if (this_ptr == NULL) {
        abort();
    }
    // code
}

int main()
{
    // default constructor call with new
    MySpace_Cls *cl1_ptr = (MySpace_Cls *) malloc (sizeof (MySpace_Cls) * 1);
    if (cl1_ptr == NULL) {
        abort();
    }
    MySpace_Cls cl1 = *cl1_ptr;
    MySpace_Cls_default_constructor (&cl1);

    int x = MySpace_Cls_foo (&cl1);

    // without new
    MySpace_Cls cl2;
    MySpace_Cls *cl2_ptr = &cl2;
    MySpace_Cls_default_constructor (&cl1);
}
