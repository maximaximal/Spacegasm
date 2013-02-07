#ifndef CSINGLETON_INCLUDED
#define CSINGLETON_INCLUDED

template <class T_DERIVED>
class TSingleton
{
    public:
        inline static T_DERIVED* Get()
        {
            if(pInstance)
            {
                return pInstance;
            }

            pInstance = new T_DERIVED;
            return pInstance;
        }
        void destroy()
        {
            if(pInstance)
            {
                delete pInstance;
                pInstance = 0;
            }
        }
        void altDestroy()
        {
            if(pInstance)
            {
                delete pInstance;
                pInstance = 0;
            }
        }

    private:
        static T_DERIVED *pInstance;
};

template <class T>
T* TSingleton<T>::pInstance = 0;

// From Wikipedia; http://de.wikipedia.org/wiki/Singleton_%28Entwurfsmuster%29
//
// Verwendung
//   class CMySingleton : public CSingleton< CMySingleton >
//   {
//      friend class CSingleton< CMySingleton >;
//
//      private:
//         CMySingleton(){}
//
//      //...
//   };

#endif // CSINGLETON_INCLUDED
