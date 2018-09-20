#include"addr.h"

record *is_full(record *p)
{
	int n = p->sz;
	if(n == 0||p->sz+3==p->capacity)
	{
		peoinfo *tmp = (peoinfo*)realloc(p->elem,sizeof(peoinfo)*p->capacity);
		if(tmp != NULL)
		{
		    p->elem = tmp;
			p->capacity += 3;
			n = 1;
		}
		else
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
	}
	return p;

}
record*initrecord()
{
	
	record *s;
	s = (record *)malloc(sizeof(record));
	if(s == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	  s->sz = 0;
	  s->capacity = 3;
	  s->elem = NULL;
	  loadcontact(s);
	return s;
}
void loadcontact(record * p)
{
	peoinfo tmp = {0};
	int count = 0;
	FILE *pfread = fopen(FILENAME,"r");
	if(pfread == NULL)
	{
		perror(" open file for read ");
		exit(EXIT_FAILURE);
	}
	   while(fread(&tmp,sizeof(peoinfo),1,pfread))
	   {
		   is_full(p);
		   p->elem[p->sz] = tmp;
		   p->sz++;
		 
	   }
	fclose(pfread);
	pfread = NULL;
}
void savecontact(record * p)
{
	int i = 0;
	FILE *pfwrite = fopen(FILENAME,"w");
	if(pfwrite == NULL)
	{
		perror("open file for write");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i<p->sz; i++)
	{
		fwrite(p->elem+i,sizeof(peoinfo),1,pfwrite);
	}
	fclose(pfwrite);
	pfwrite = NULL;
}
void add(record *p)
{
	assert(p!=NULL);
	is_full(p);
	printf("��������:>");
	scanf("%s",&p->elem[p->sz].name);
	printf("��������:>");
	scanf("%d",&p->elem[p->sz].age);
	printf("�����Ա�:>");
	scanf("%s",&p->elem[p->sz].sex);
	printf("�����ַ:>");
	scanf("%s",&p->elem[p->sz].addr);
	p->sz++;
	printf("���ӳɹ�\n");
}
static int sea(record *p)
{
	int i = 0;
	char name[10] = {'\0'};
	assert(p!=NULL);

	printf("��������:>");
	scanf("%s",&name);
	for(i=0; i<p->sz; i++)
	{
	if(strcmp(name,(p->elem[i].name))==0)
		return i;
	}
		return -1;
}
void search(record *p)
{
	int i = 0;
	i = sea(p);
	assert(p!=NULL);

	if(i != -1)
	{
		printf("�ҵ���\n");
		printf("����:%s,����:%d,�Ա�:%s,��ַ:%s\n",
			p->elem[i].name,
			p->elem[i].age,
			p->elem[i].sex,
			p->elem[i].addr);
	}
	else
		printf("û���ҵ�\n");
}

void show(record *p)
{
	int j = 0;
	assert(p!=NULL);

	printf("����    ����   �Ա�   ��ַ\n");
	for(j=0; j<p->sz; j++)
	{
		printf("%-6s %-6d %-6s %-6s\n",
			p->elem[j].name,
			p->elem[j].age,
			p->elem[j].sex,
			p->elem[j].addr);
	}
}
void empty(record *p)
{
	assert(p!=NULL);
	p->sz = 0;	
}
void del(record *p)
{
	int ret = 0;
	assert(p!=NULL);
	ret = sea(p);
	if(ret != -1||ret<=p->sz)
	{
		int i = 0;
		for(i=ret; i<p->sz-1; i++)
		{
			p->elem[i]=p->elem[i+1];
		}
		p->sz--;
	}
	else
		printf("û���ҵ���ϵ��\n");

}
void sort(record *p)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	assert(p!=NULL);
	if(p->sz == 0)
		return ;
	for(i=0; i<p->sz-1; i++)
	{
		for(j=0; j<p->sz-1-i; j++)
		{
	   if(strcmp(p->elem[j].name ,p->elem[j+1].name)>0)
	    {
		  peoinfo tmp = p->elem[j];
		  p->elem[j]=p->elem[j+1];
		  p->elem[j+1] = tmp;
		  flag = 1;
	    }
	   if(flag = 0)
		   break;
       }
		  
	}
	printf("����ɹ�\n");
}
void mod(record *p)
{
	int ret = 0;
	assert(p!=NULL);
	ret = sea(p);
	if(ret!=-1)
	{
		printf("����Ҫ�޸ĵ�����:");
		scanf("%s",&p->elem[ret].name );
		printf("����Ҫ�޸ĵ�����:");
		scanf("%d",&p->elem[ret].age );
		printf("����Ҫ�޸ĵ��Ա�:");
		scanf("%s",&p->elem[ret].sex );
		printf("����Ҫ�޸ĵĵ�ַ:");
		scanf("%s",&p->elem[ret].addr );
		printf("�޸ĳɹ�\n");
	}
	else
		printf("û���ҵ���ϵ��\n");
	
}
void destroycontact(record * p)
{
	 savecontact(p);
	free(p->elem);
		p->elem = NULL;
		free(p);
		p = NULL;
}