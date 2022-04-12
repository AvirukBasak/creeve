/**
 * WARNING: DEMO CREEVE CODE, WILL NOT COMPILE
 */

MySpace
{
    class Cls
    {
        int memeber;
        struct member2
        {
            // more stuff
        }
        // @overrrideAllocation
        // the above annotation allow you to custom define the malloc call
        constructor ()
        {
            // code
        }
        constructor (int x)
        {
            this.memeber = x;
            // code
        }
        destructor ()
        {
            // code
        }
        int foo ()
        {
            this.memeber = 5;
            this.bar ();
        }
        void bar ()
        {
            // code
        }
    }
}

MySpace::Cls cl1 = MySpace::Cls ();
int x = cl1.foo ();

// -----------------------------------------

// Compilation Result:

typedef struct MySpace_Cls
{
    int memeber;
    struct member2
    {
        // more stuff
    };
}* MySpace_Cls;

MySpace_Cls MySpace_Cls_default_constructor ()
{
    MySpace_Cls this = malloc (sizeof (struct MySpace_Cls) * 1));
    // code
    return this;
}

MySpace_Cls MySpace_Cls_param_constructor (int x)
{
    MySpace_Cls this = malloc (sizeof (struct MySpace_Cls) * 1));
    this.member = x;
    // code
    return this;
}

void MySpace_Cls_destructor (MySpace_Cls this)
{
    // code
    free (this);
}

int MySpace_Cls_foo (MySpace_Cls this)
{
    this.memeber = 5;
    MySpace_Cls_bar (this);
}

void MySpace_Cls_bar (MySpace_Cls this)
{
    // code
}

MySpace_Cls cl1 = MySpace_Cls_constructor ();
int x = MySpace_Cls_foo (cl1);
