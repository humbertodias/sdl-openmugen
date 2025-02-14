#ifndef __MEMMANAGER__H
#define __MEMMANAGER__H

class CAllocater
{

   char strAllocName[255] = {};
   size_t  nAllocSize = 0;
   size_t  nAllocNumber = 0;
   size_t  nMemListSize = 0;
   MEMLIST *lpMemList = NULL;
   bool bFree;
   
enum { FREE=0x00,
       ALLOC=0xff

      };
      void SetMemListFree(MEMLIST* lpList); 
public:
      //Constructor & Desctructor 
      CAllocater(char *strName);
      ~CAllocater();
      
      void ShowMemUsage();
      void* Alloc(size_t nSize,int nMemInit = 0);
      void* Realloc(void *CurMem,size_t nSize);
      void  Free(void *CurMem);
      void  FreeAllocater();
      void ResetAllocater();
      size_t   GetMemUsage(){return nAllocSize;}
      char *GetName(){return strAllocName;}        
      
};

class CMemManager
{
     CAllocater *lpAlloc[7];                 
public:
      //Constructor & Desctructor  
      CMemManager();
      ~CMemManager();
      
      void InitManager();
      CAllocater *GetAllocater(int nAllocater);
      void FreeManager();
      size_t GetMemUsage();
      
};

  
#endif
