#include <string.h>
#include<stdlib.h>
#include"fonction.h"
#include <stdio.h>
void ajouter (char login[],char password[], int role)
{
	FILE *f;
	f=fopen("/home/lenovo/Projets/projet3/src/user.txt","a+");
	if(f!=NULL){
		fprintf(f,"%s %s %d \n",login,password,role);
	}
	fclose(f);
}
void afficher()
{
	FILE *f;
	f=fopen("/home/lenovo/Projets/projet3/src/user.txt","r");
	char login[20],password[20];
	int role;
	while(fscanf(f,"%s %s %d",login,password,&role)!=EOF){
		fprintf(f,"%s %s %d", login,password,role);
	}
	fclose(f);
}
int verifier(char login[],char password[])
{
	FILE *f;
	int role;
	char login1[20];char password1[20];
	f=fopen("/home/lenovo/Projets/projet3/src/user.txt","r");
	
	while(fscanf(f,"%s %s ", login1,password1 )!=EOF){
		if (strcmp(login1,login)==0 && strcmp(password1,password)==0)
		{
			fclose(f);
			return (1);
		}
	}
	fclose(f);
	return 0;
}




void afficher1(GtkWidget *plistview)
{ 
enum { COL_SEANCE,
       COL_DATE,
       COL_TYPE,
       NUM_COLS
      };
char seance[20],date[20],type[20];
GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
FILE *f;
f=fopen("/home/lenovo/Projets/projet3/src/rdv.txt","r");
if(f!=NULL){
       while(fscanf(f,"%s %s %s",seance,date,type)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                          COL_SEANCE, seance,
		          COL_DATE, date,
		          COL_TYPE, type,
                       -1);}
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("seance",celrender,"text",COL_SEANCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("date",celrender,"text",COL_DATE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("type",celrender,"text",COL_TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);


	gtk_tree_view_set_model (GTK_TREE_VIEW(plistview), GTK_TREE_MODEL (liststore));

}
fclose(f);
}
void ajouter1(char seance[],char date[],char type[])
{
	FILE *f ;
	f=fopen("/home/lenovo/Projets/projet3/src/rdv.txt","a+");
	if(f!=NULL)
	{
		fprintf(f,"%s %s %s \n",seance,date,type);
	}
	fclose(f);
}
void modifier(char seance[],char date[] ,char type[])
{
	char seance1[20], date1[20],type1[20];
	FILE *f, *tmp;
	f=fopen("/home/lenovo/Projets/projet3/src/rdv.txt","r");
	tmp=fopen("/home/lenovo/Projets/projet3/src/rdv.tmp","a+");
	while(fscanf(f,"%s %s %s",seance1,date1,type1)!=EOF){
		if(!strcmp(date,date1)){fprintf(tmp,"%s %s %s\n",seance,date,type);}
else fprintf(tmp,"%s %s %s\n",seance1,date1,type1);
}
fclose(f);
fclose(tmp);
rename("/home/lenovo/Projets/projet3/src/rdv.tmp","/home/lenovo/Projets/projet3/src/rdv.txt");
}






void supprimer(char seance[],char date[] ,char type[])
{
	char seance1[20], date1[20],type1[20];
	FILE *f, *tmp;
	f=fopen("/home/lenovo/Projets/projet3/src/rdv.txt","r");
	tmp=fopen("/home/lenovo/Projets/projet3/src/rdv.tmp","a+");
	while(fscanf(f,"%s %s %s",seance1,date1,type1)!=EOF){
		if(!strcmp(date,date1)){fprintf(tmp,"%s %s %s\n",seance="",date="",type="");}
else fprintf(tmp,"%s %s %s\n",seance1,date1,type1);
}
fclose(f);
fclose(tmp);
rename("/home/lenovo/Projets/projet3/src/rdv.tmp","/home/lenovo/Projets/projet3/src/rdv.txt");
}






void afficher_fiche(GtkWidget *filistview)
{ 
enum { COL_NOM,
       COL_PRENOM,
       COL_CIN,
       COL_ETAT,
       COL_AGE,
       COL_ADRESSE,
       COL_TAILLE,	
       NUM_COLS
      };
char nom[20],prenom[20],cin[20],etat[30],adresse[50],taille[10];int age;
GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
GtkTreeIter *iter;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
FILE *f;
f=fopen("/home/lenovo/Projets/projet3/src/etat.txt","r");
if(f!=NULL){
       while(fscanf(f,"%s %s %s %s %d %s %s",nom,prenom,cin,etat,&age,adresse,taille)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                          COL_NOM, nom,
		          COL_PRENOM, prenom,
		          COL_CIN, cin,
			  COL_ETAT,etat,
			  COL_AGE,age,
			  COL_ADRESSE,adresse,
			  COL_TAILLE,taille,
                       -1);}
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("nom",celrender,"text",COL_NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("prenom",celrender,"text",COL_PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("cin",celrender,"text",COL_CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Tension artérielle",celrender,"text",COL_ETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);
	
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("age",celrender,"text",COL_AGE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("adresse",celrender,"text",COL_ADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);
	
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("Indice de masse corporelle",celrender,"text",COL_TAILLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(filistview),col);

	gtk_tree_view_set_model (GTK_TREE_VIEW(filistview), GTK_TREE_MODEL (liststore));

}
fclose(f);
}
void ajouter_cas_urgence (char cas[])
{
	FILE *f;
	f=fopen("/home/lenovo/Projets/projet3/src/cas_urgence.txt","a+");
	if(f!=NULL){
		fprintf(f,"%s \n",cas);
	}
	fclose(f);
}







 
                          
