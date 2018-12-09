
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"

void
on_button_ok_clicked(GtkWidget *objet_graphique, gpointer user_data){
int x;
GtkWidget *a ,*b ,*c ,*window1, *menu_coach ,*incorrect;
char login[20]; char password[20];
window1=lookup_widget(objet_graphique,"window1");
a=lookup_widget(objet_graphique,"entry_login");
b=lookup_widget(objet_graphique,"Entry_password");
incorrect=lookup_widget(objet_graphique,"label_verif");
strcpy(login,gtk_entry_get_text(GTK_ENTRY(a)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(b)));
x=verifier(login,password);
if (x==1)
{
menu_coach=create_menu_coach();
gtk_widget_show (menu_coach);
gtk_widget_hide(window1);
}
else
{
gtk_label_set_text(GTK_LABEL(incorrect),"invalid");
}
}









	



void
on_button_ajout_clicked              (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window2,*window_ajout;
	window2=lookup_widget(objet_graphique,"window2");
	window_ajout=create_window_ajout();
	gtk_widget_show(window_ajout);
	gtk_widget_hide(window2);
}


void
on_button_ajouter2_clicked             (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *a, *b,*d,*e , *c ,*window_ajout,*window2,*list_view ,*menu_coach,*combobox_periode,*combobox_type ;
	char seance[20];char date[50]; char type[20];char jour[20];char mois[20];char anne[2050];
	
	
	combobox_periode=lookup_widget(objet_graphique,"combobox_periode");
	b=lookup_widget(objet_graphique,"spinbutton_cjour");
	d=lookup_widget(objet_graphique,"spinbutton_cmois");
	e=lookup_widget(objet_graphique,"spinbutton_canne");
	combobox_type=lookup_widget(objet_graphique,"combobox_type");
	c=lookup_widget(objet_graphique,"combobox_type");


										strcpy(seance,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_periode)));
	strcpy(jour,gtk_entry_get_text(GTK_ENTRY(b)));
	strcpy(mois,gtk_entry_get_text(GTK_ENTRY(d)));
	strcpy(anne,gtk_entry_get_text(GTK_ENTRY(e)));
	strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_type)));
	sprintf(date,"%s/%s/%s",jour,mois,anne);
	

	ajouter1(seance,date,type);
	
	window2=create_window2();
	menu_coach=lookup_widget(objet_graphique,"menu_coach");
	gtk_widget_hide(menu_coach);
	gtk_widget_show(window2);
	list_view=lookup_widget(window2,"treeview1");
	afficher1(list_view);
	window_ajout=lookup_widget(objet_graphique,"window_ajout");
	gtk_widget_show (window2);
	
	gtk_widget_hide (window_ajout);
}


void
on_button1_clicked                      (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window2,*window_ajout;
	window2=lookup_widget(objet_graphique,"window2");
	window_ajout=create_window_ajout();
	gtk_widget_show(window_ajout);
	gtk_widget_hide(window2);
}


void
on_button2_clicked                    (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button3_clicked                     (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2 ,*menu_coach, *list_view ;
window2=create_window2();
menu_coach=lookup_widget(objet_graphique,"menu_coach");
gtk_widget_hide(menu_coach);
gtk_widget_show(window2);







list_view=lookup_widget(window2,"treeview1");
afficher1(list_view);
gtk_widget_show (window2);
}


void
on_button_adherent_clicked             (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *menu_coach;
	GtkWidget *window_adherent,*list_view;
	menu_coach=lookup_widget(objet_graphique,"menu_coach");
	window_adherent =create_window_adherent();
	
	
	list_view=lookup_widget(window_adherent,"treeview2");
	afficher_fiche(list_view);
	gtk_widget_show(window_adherent);
	gtk_widget_hide(menu_coach);
	

}


void
on_button_urgence_clicked               (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	
	
	GtkWidget *current;
	GtkWidget *window_urgence;
	current=lookup_widget(objet_graphique,"menu_coach");
	window_urgence =create_window_urgence();
	gtk_widget_show(window_urgence);
	gtk_widget_hide(current);
	
}


void
on_button_retour1_clicked              (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	
	GtkWidget *current;
	GtkWidget *menu_coach;
	current=lookup_widget(objet_graphique,"window_adherent");
	menu_coach =create_menu_coach();
	gtk_widget_show(menu_coach);
	gtk_widget_hide(current);
	
}


void
on_button_return2_clicked               (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	
	GtkWidget *current;
	GtkWidget *menu_coach;
	current=lookup_widget(objet_graphique,"window_urgence");
	menu_coach =create_menu_coach();
	gtk_widget_show(menu_coach);
	gtk_widget_hide(current);
	
}


void
on_button_return3_clicked              (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	
	GtkWidget *current;
	GtkWidget *window2;
	current=lookup_widget(objet_graphique,"window_ajout");
	window2 =create_window2();
	
	gtk_widget_hide(current);
GtkWidget *window_ajout, *list_view ;
window2=create_window2();
window_ajout=lookup_widget(objet_graphique,"window_ajout");
gtk_widget_hide(window_ajout);
afficher1(list_view);
gtk_widget_show(window2);







list_view=lookup_widget(window2,"treeview1");
afficher1(list_view);


	
}


void
on_button_modifier_clicked             (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *seancek,*datek,*typek,*window3,*List_View,*window2;
	char seance[20],date[20],type[20];
	seancek=lookup_widget(objet_graphique,"entry_seance");
	datek=lookup_widget(objet_graphique,"entry_date");
	typek=lookup_widget(objet_graphique,"entry_type");
	strcpy(seance,gtk_entry_get_text(GTK_ENTRY(seancek)));
	strcpy(date,gtk_entry_get_text(GTK_ENTRY(datek)));
	strcpy(type,gtk_entry_get_text(GTK_ENTRY(typek)));
	modifier(seance,date,type);
	
	window3=lookup_widget(objet_graphique,"window3");
	gtk_widget_hide(window3);
	List_View=lookup_widget(window2,"treeview1");
	afficher1(List_View);
	gtk_widget_show(window2);









		
}


void
on_button4_clicked                    (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	
}


void
on_treeview1_row_activated             (GtkWidget    *tree,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	
	GtkWidget *seancek,*datek,*typek,*window3,*win,*treeview;
	gchar *seance,*date,*type;
	win=lookup_widget(tree,"window2");
	treeview=lookup_widget(tree,"treeview1");
	window3=create_window3();
	seancek=lookup_widget(window3,"entry_seance");
	datek=lookup_widget(window3,"entry_date");
	typek=lookup_widget(window3,"entry_type");
	GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&seance,1,&date,2,&type,-1);
	printf("%s %s %s",seance,date,type);
	gtk_entry_set_text(GTK_ENTRY (seancek),_(seance));
	gtk_entry_set_text(GTK_ENTRY (datek),_(date));
	gtk_entry_set_text(GTK_ENTRY (typek),_(type));
	gtk_widget_show(window3);
	gtk_widget_hide(win);
	
	
}


void
on_button5_clicked                     (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	
	GtkWidget *seancek,*datek,*typek,*list_view,*window3,*window2;
	char seance[20],date[20],type[20];
	seancek=lookup_widget(objet_graphique,"entry_seance");
	

	datek=lookup_widget(objet_graphique,"entry_date");
	typek=lookup_widget(objet_graphique,"entry_type");
	strcpy(seance,gtk_entry_get_text(GTK_ENTRY(seancek)));
	strcpy(date,gtk_entry_get_text(GTK_ENTRY(datek)));
	strcpy(type,gtk_entry_get_text(GTK_ENTRY(typek)));
	modifier(seance,date,type);
	window3=lookup_widget(objet_graphique,"window3");
	gtk_widget_hide(window3);
	
window2=create_window2();
window3=lookup_widget(objet_graphique,"window3");
list_view=lookup_widget(window2,"treeview1");
afficher1(list_view);
gtk_widget_show(window2);

}


void
on_button_return_w3_vers_wa_clicked    (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window3;
	GtkWidget *window2 ,*list_view;
	gtk_widget_hide(window2);	
	window3=lookup_widget(objet_graphique,"window3");
	window2=create_window2();
	
	gtk_widget_hide(window3);

window3=lookup_widget(objet_graphique,"window3");
list_view=lookup_widget(window2,"treeview1");
afficher1(list_view);
gtk_widget_show(window2);

}


void
on_button_supprimer_clicked             (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	
	GtkWidget *seancek,*datek,*typek,*list_view,*window3,*window2;
	char seance[20],date[20],type[20];
	seancek=lookup_widget(objet_graphique,"entry_seance");
	

	datek=lookup_widget(objet_graphique,"entry_date");
	typek=lookup_widget(objet_graphique,"entry_type");
	strcpy(seance,gtk_entry_get_text(GTK_ENTRY(seancek)));
	strcpy(date,gtk_entry_get_text(GTK_ENTRY(datek)));
	strcpy(type,gtk_entry_get_text(GTK_ENTRY(typek)));
	supprimer(seance,date,type);
	window3=lookup_widget(objet_graphique,"window3");
	gtk_widget_hide(window3);
	
window2=create_window2();
window3=lookup_widget(objet_graphique,"window3");
list_view=lookup_widget(window2,"treeview1");
afficher1(list_view);
gtk_widget_show(window2);
}


void
on_button_w2_vers_menu_clicked      (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *current;
	GtkWidget *menu_coach;
	current=lookup_widget(objet_graphique,"window2");
	menu_coach =create_menu_coach();
	gtk_widget_show(menu_coach);
	gtk_widget_hide(current);
}


void
on_button_cas_urgence_clicked           (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *a ;
	char cas[20];
	a=lookup_widget(objet_graphique,"entry_cas_urgence");
	strcpy(cas,gtk_entry_get_text(GTK_ENTRY(a)));
	
	ajouter_cas_urgence(cas);
	
	
	
	
}

