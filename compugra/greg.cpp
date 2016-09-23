//Semestre 2017 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Augusto Meza Pe�a				        ******//
//*************	Mu�oz Alvarez Rosa Maria Yolotzin		******//
//************************************************************//
#include "Main.h"

DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

bool boca_open = true;

float black[3] = { 0.0f,0.0f,0.0f };
float white[3] = { 1.0f,1.0f ,1.0f };
float tetera[3] = {0.7882f,0.7490f,0.6352f};
float tetera_sombra[3] = { 0.5450f,0.5176f,0.4352f};
float tetera_luz[3] = {0.9450f,0.9058f,0.7803f};
float hair[3] = {0.3568f,0.3176f,0.2078f};
float skin[3] = {0.8470f,0.7254f,0.5647f};
float nose[3] = {0.8627f,0.6666f,0.5960f};
float teeth[3] = {0.9294f,0.9058f,0.7921f};
float boca[3] = {0.5529f,0.3882f,0.2980f};
float lengua[3] = {0.8117f,0.4823f,0.4352f};
float oberol[3] = {0.4666f,0.5254f,0.4117f};
float shirt[3] = {0.8745f,0.8470f,0.7607f};
float strip[3] = {0.3254f,0.2352f,0.1058f };
float back[3] = {0.3607f,0.3098f,0.2156f};
float bag[3] = {0.4588f,0.3921f,0.2747f};
float coin[3] = {0.6666f,0.5607f,0.3294f};
float coin_sombra[3] = { 0.6117f,0.4941f,0.1960f };
float coin_luz[3] = {0.7843f,0.7098f,0.4078f};
float shirt_sombra[3] = { 0.8039f,0.7764f, 0.6941f};

void f(int x, int y) {
	glVertex3d(x, y, -0.2);
}

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);				//Blanco de fondo
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview
	glLineWidth(1.5);


	//Augusto
	/************************/
	/*			Tetera		*/
	/************************/
	/*			boca tetera		*/
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(tetera);
	f(978, 300);
	f(985, 303);
	f(993, 306);
	f(1000, 307);
	f(1007, 309);
	f(1015, 308);
	f(1025, 308);
	f(1026, 307);
	f(1027, 308);
	f(1028, 303);
	f(1029, 304);
	f(1029, 300);
	f(1024, 296);
	f(1013, 290);
	f(996, 274);
	f(987, 252);
	f(977, 196);
	f(964, 163);
	f(937, 139);
	f(913, 127);
	f(906, 125);
	f(888, 122);
	f(881, 123);
	f(862, 128);
	glEnd();
	glBegin(GL_POLYGON);
	f(872, 187);
	f(869, 225);
	f(878, 224);
	f(885, 224);
	f(897, 224);
	f(909, 228);
	f(925, 237);
	f(937, 246);
	f(941, 249);
	f(963, 239);
	glEnd();
	glBegin(GL_POLYGON);
	f(862, 128);
	f(870, 157);
	f(935, 142);
	glEnd();
	glBegin(GL_POLYGON);
	f(870, 157);
	f(872, 187);
	f(949, 243);
	f(935, 142);
	glEnd();
	glBegin(GL_POLYGON);
	f(938, 166);
	f(941, 249);
	f(953, 266);
	f(966, 293);
	f(978, 300);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(tetera_sombra);
	f(978, 300);
	f(980, 297);
	f(985, 297);
	f(997, 302);
	f(1005, 306);
	f(1000, 307);
	f(993, 306);
	f(985, 303);
	glEnd();
	glBegin(GL_POLYGON);
	f(872, 187);
	f(870, 209);
	f(880, 208);
	f(899, 210);
	f(912, 216);
	f(947, 243);
	f(949, 243);
	f(949, 241);
	f(925, 213);
	f(907, 200);
	f(892, 192);
	f(880, 188);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(tetera_luz);
	f(877, 133);
	f(878, 146);
	f(885, 147);
	f(892, 147);
	f(906, 151);
	f(929, 163);
	f(900, 135);
	f(883, 136);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(tetera_luz);
	f(929, 163);
	f(943, 174);
	f(950, 182);
	f(952, 184);
	f(953, 187);
	f(952, 180);
	f(939, 159);
	f(915, 142);
	f(900, 135);
	glEnd();
	glBegin(GL_LINE_STRIP); //<contorno boca tetera
	glColor3fv(black);
	f(869, 225);
	f(878, 224);
	f(885, 224);
	f(897, 224);
	f(909, 228);
	f(925, 237);
	f(937, 246);
	f(941, 249);
	f(953, 266);
	f(966, 293);
	f(978, 300);
	f(985, 303);
	f(993, 306);
	f(1000, 307);
	f(1007, 309);
	f(1015, 308);
	f(1025, 308);
	f(1026, 307);
	f(1027, 308);
	f(1028, 303);
	f(1029, 304);
	f(1029, 300);
	f(1024, 296);
	f(1013, 290);
	f(996, 274);
	f(987, 252);
	f(977, 196);
	f(964, 163);
	f(937, 139);
	f(913, 127);
	f(906, 125);
	f(888, 122);
	f(881, 123);
	f(862, 128);
	f(870, 157);
	f(872, 187);
	glEnd(); // </ contorno boca tetera
	glBegin(GL_LINE_STRIP); //<contorno cuerpo tetera
	f(850, 333);
	f(865, 255);
	f(868, 225);
	f(872, 187);
	f(870, 157);
	f(862, 128);
	f(849, 106);
	f(840, 93);
	f(828, 81);
	f(828, 77);
	f(832, 72);
	f(844, 68);
	f(847, 65);
	f(847, 58);
	f(844, 52);
	f(827, 47);
	f(799, 41);
	f(750, 36);
	f(711, 35);
	f(681, 36);
	f(643, 39);
	f(620, 43);
	f(590, 49);
	f(571, 54);
	f(549, 60);
	f(530, 66);
	f(518, 72);
	f(503, 80);
	f(489, 88);
	f(487, 91);
	f(486, 92);
	f(486, 104);
	f(490, 108);
	f(492, 108);
	f(509, 108);
	f(512, 109);
	f(513, 111);
	f(515, 113);
	f(516, 117);
	f(516, 121);
	f(506, 135);
	f(502, 144);
	f(497, 157);
	f(493, 168);
	f(491, 183);
	f(489, 198);
	f(490, 217);
	f(493, 240);
	f(497, 257);
	f(507, 289);
	f(515, 312);
	f(520, 326);
	f(529, 344);
	f(538, 363);
	glEnd();// </ contorno cuerpo tetera
	glBegin(GL_LINE_STRIP);// <punta boca tetera
	f(978, 300);
	f(980, 297);
	f(985, 297);
	f(997, 302);
	f(1005, 306);
	f(1000, 307);
	f(993, 306);
	f(985, 303);
	glEnd(); // </ punta boca tetera
	glBegin(GL_LINE_STRIP);// <mango exterior tetera
	f(495, 159);
	f(474, 176);
	f(463, 186);
	f(450, 201);
	f(442, 211);
	f(433, 223);
	f(425, 236);
	f(418, 251);
	f(410, 267);
	f(407, 280);
	f(404, 291);
	f(403, 298);
	f(403, 309);
	f(404, 315);
	f(406, 319);
	f(409, 324);
	f(414, 331);
	f(419, 335);
	f(430, 340);
	f(440, 343);
	f(449, 345);
	f(460, 346);
	f(472, 347);
	f(482, 347);
	f(512, 347);
	f(519, 346);
	f(528, 344);
	glEnd(); // </ mango exterior tetera
	glBegin(GL_LINE_STRIP);// < mango interior tetera
	f(489, 211);
	f(481, 219);
	f(475, 227);
	f(467, 237);
	f(460, 247);
	f(453, 258);
	f(446, 273);
	f(442, 284);
	f(439, 292);
	f(439, 301);
	f(442, 306);
	f(445, 310);
	f(450, 312);
	f(456, 313);
	f(466, 314);
	f(492, 314);
	f(514, 313);
	glEnd();// </ mango interior tetera
	/************************/
	/*			Cuerpo		*/
	/************************/
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);//inicio shirt
	glColor3fv(shirt);
	f(529,740);
	f(578,750 );
	f(623,755 );
	f(623,710 );
	f(583,695 );
	f(556,682 );
	f(540,707 );
	glEnd();
	glBegin(GL_POLYGON);
	f(537,740 );
	f(584,751 );
	f(596,785 );
	f(545,798 );
	f(537,768 );
	glEnd();
	glBegin(GL_POLYGON);
	f(546,797 );
	f(627,770 );
	f(657,802 );
	f(573,855 );
	glEnd();
	glBegin(GL_POLYGON);
	f(560,791 );
	f(583,763 );
	f(609,776 );
	glEnd(); // Fin shirt
	glBegin(GL_POLYGON);//oberol
	glColor3fv(oberol);
	f(508, 835);
	f(507, 853);
	f(507, 900);
	f(508, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(627, 769);
	f(619, 773);
	f(612, 774);
	f(603, 775);
	f(597, 774);
	f(594, 772);
	f(591, 769);
	f(588, 759);
	f(586, 752);
	f(624, 757);
	glEnd();
	glBegin(GL_POLYGON);
	f(623, 757);
	f(654,769);
	f(626,740 );
	glEnd();
	glBegin(GL_POLYGON);
	f(508, 835);
	f(512, 809);
	f(512, 900);
	f(508, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(513, 793);
	f(512, 809);
	f(512, 900);
	f(513, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(513, 793);
	f(514, 790);
	f(514, 900);
	f(513, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(516, 779);
	f(514, 790);
	f(514, 900);
	f(516, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(516, 779);
	f(514, 790);
	f(514, 900);
	f(516, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(516, 779);
	f(522, 757);
	f(522, 900);
	f(516, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(528, 741);
	f(522, 757);
	f(522, 900);
	f(528, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(528, 741);
	f(535, 743);
	f(535, 900);
	f(528, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(537, 764);
	f(535, 743);
	f(535, 900);
	f(537, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(537, 764);
	f(540, 783);
	f(540, 900);
	f(537, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(549, 808);
	f(540, 783);
	f(540, 900);
	f(549, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(549, 808);
	f(556, 818);
	f(556, 900);
	f(549, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(576, 830);
	f(556, 818);
	f(556, 900);
	f(576, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(576, 830);
	f(596, 831);
	f(596, 900);
	f(576, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(607, 828);
	f(596, 831);
	f(596, 900);
	f(607, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(607, 828);
	f(636, 817);
	f(636, 900);
	f(607, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(651, 808);
	f(636, 817);
	f(636, 900);
	f(651, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(654, 807);
	f(651, 808);
	f(651, 900);
	f(654, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(656, 807);
	f(654, 807);
	f(654, 900);
	f(656, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(656, 807);
	f(659, 803);
	f(659, 900);
	f(656, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(664, 802);
	f(659, 803);
	f(659, 900);
	f(664, 900);
	glEnd();
	glBegin(GL_POLYGON);
	f(664, 802);
	f(668, 799);
	f(668, 900);
	f(664, 900);
	glEnd();
	glBegin(GL_POLYGON);
		f(675, 805);
		f(668, 799);
		f(668, 900);
		f(675, 900);
	glEnd();
	glBegin(GL_POLYGON);
		f(675, 805);
		f(679, 803);
		f(679, 900);
		f(675, 900);
	glEnd();
	glBegin(GL_POLYGON);
		f(680, 802);
		f(679, 803);
		f(679, 900);
		f(680, 900);
	glEnd();
	glBegin(GL_POLYGON);
		f(687, 794);
		f(679, 794);
		f(679, 900);
		f(687, 900);
	glEnd();
	glBegin(GL_POLYGON);
		f(691, 798);
		f(687, 794);
		f(687, 900);
		f(691, 900);
	glEnd();
	glBegin(GL_POLYGON);
		f(691, 799);
		f(738, 828);
		f(738, 900);
		f(691, 900);
	glEnd();
	glBegin(GL_POLYGON);
		f(772, 846);
		f(738, 828);
		f(738, 900);
		f(772, 900);
	glEnd();
	glBegin(GL_POLYGON);
		f(745, 831);
		f(756, 837);
		f(767, 843);
		f(781, 850);
		f(794, 856);
		f(794, 900);
		f(745, 900);
	glEnd();
	glBegin(GL_POLYGON);
		f(794, 856);
		f(809, 862);
		f(820, 866);
		f(830, 870);
		f(840, 873);
		f(855, 877);
		f(855, 900);
		f(794, 900);
	glEnd();
	glBegin(GL_POLYGON);
		f(855, 877);
		f(868, 881);
		f(880, 884);
		f(892, 886);
		f(902, 887);
		f(914, 889);
		f(915, 900);
		f(855, 900);
	glEnd();// fin oberol
	glBegin(GL_POLYGON); // inicio strip
	glColor3fv(strip);
	f(626, 710);
	f(639, 725);
	f(649, 734);
	f(645, 759);
	f(624, 737);
	f(624, 738);
	f(610, 722);
	f(601, 711);
	f(591, 699);
	glEnd();
	glBegin(GL_POLYGON);
	f(649, 734);
	f(686, 766);
	f(708, 782);
	f(694, 800);
	f(690, 796);
	f(645, 759);
	glEnd();
	glBegin(GL_POLYGON);
	f(708, 782);
	f(720, 790);
	f(730, 797);
	f(748, 808);
	f(765, 817);
	f(777, 824);
	f(767, 843);
	f(756, 837);
	f(745, 831);
	f(731, 823);
	f(718, 815);
	f(694, 800);
	glEnd();
	glBegin(GL_POLYGON);
	f(777, 824);
	f(804, 837);
	f(826, 845);
	f(843, 851);
	f(840, 873);
	f(830, 870);
	f(820, 866);
	f(809, 862);
	f(794, 856);
	f(781, 850);
	f(767, 843);
	glEnd();
	glBegin(GL_POLYGON);
	f(843, 851);
	f(863, 857);
	f(882, 862);
	f(897, 866);
	f(908, 868);
	f(915, 869);
	f(915, 876);
	f(914, 889);
	f(902, 887);
	f(892, 886);
	f(880, 884);
	f(868, 881);
	f(855, 877);
	f(840, 873);
	glEnd();// fin strip
	glBegin(GL_POLYGON);// inicio backpack
	glColor3fv(back);
	f(945, 900);
	f(945, 895);
	f(946, 892);
	f(946, 886);
	f(947, 870);
	f(940, 856);
	f(934, 850);
	f(928, 848);
	f(922, 848);
	f(916, 850);
	f(916, 900);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3fv(bag);
	f(941, 900);
	f(941, 892);
	f(938, 884);
	f(934, 874);
	f(930, 870);
	f(924, 866);
	f(919, 867);
	f(918, 868);
	f(916, 870);
	f(916, 900);
	glEnd();//fin backpack
	glBegin(GL_POLYGON);//mano
	glColor3fv(skin);
	f(687, 794);
	f(689, 793);
	f(690, 791);
	f(690, 789);
	f(690, 787);
	f(687, 784);
	f(684, 782);
	f(676, 778);
	f(643, 776);
	f(642, 765);
	f(638, 765);
	f(630, 758);
	f(623, 757);
	f(621, 762);
	f(623, 765);
	f(627, 769);
	f(627, 769);
	f(632, 774);
	f(632, 780);
	glEnd();
	glBegin(GL_POLYGON); // 2do dedo
	f(632, 774);
	f(632, 784);
	f(628, 794);
	f(628, 800);
	f(629, 801);
	f(631, 802);
	f(634, 801);
	f(637, 797);
	f(641, 790);
	f(641, 791);
	f(643, 787);
	f(647, 784);
	glEnd();
	glBegin(GL_POLYGON); // < debajo segundo dedo
	f(641, 791);
	f(643, 787);
	f(647, 784);
	f(650, 785);
	f(651, 786);
	f(651, 798);
	glEnd();
	glBegin(GL_POLYGON); // tercer dedo
	f(649, 784);
	f(651, 786);
	f(651, 798);
	f(651,806);
	f(656,805 );
	f(658,802 );
	f(658,800 );
	f(659, 801);
	f(660, 795);
	f(660, 790);
	f(663, 788);
	glEnd();
	glBegin(GL_POLYGON); // debajo tercer dedo
	f(659, 801);
	f(660, 795);
	f(661, 790);
	f(663, 789);
	f(664, 789);
	f(666, 792);
	f(669, 798);
	glEnd();
	glBegin(GL_POLYGON);//ultimo dedo al fin
	f(663, 789);
	f(664, 789);
	f(666, 792);
	f(669, 798);
	f(669, 798);
	f(671, 801);
	f(674, 804);
	f(676, 804);
	f(679, 803);
	f(679, 801);
	f(679, 796);
	f(678, 793);
	f(678,790);
	glEnd();
	glBegin(GL_POLYGON); // < coin up
	glColor3fv(coin);
	f(642, 765);
	f(644, 768);
	f(652, 770);
	f(657, 772);
	f(664, 773);
	f(669, 774);
	f(676, 773);
	f(675, 774);
	f(677, 772);
	f(676, 768);
	f(674, 765);
	f(670, 762);
	f(665, 760);
	f(660, 759);
	f(654, 758);
	f(649, 758);
	f(645, 759);
	glEnd(); // </ coin up
	glBegin(GL_POLYGON); // < coin up light
	glColor3fv(coin_luz);
	f(655,767 );
	f(666,769 );
	f(665,762 );
	f(658,759 );
	f(653,759 );
	glEnd();// </ coin up light
	glBegin(GL_POLYGON);// < coin up dark
	glColor3fv(coin_sombra);
	f(644,766);
	f(649,768 );
	f(657,772 );
	f(666,772 );
	f(675,773 );
	f(675,770 );
	f(666,771 );
	f(654,768 );
	f(644,763 );
	glEnd();// </ coin up dark
	glBegin(GL_POLYGON); // < coin down dark
	glColor3fv(coin_sombra);
	f(642, 765);
	f(644, 768);
	f(652, 770);
	f(657, 772);
	f(664, 773);
	f(669, 774);
	f(676, 773);
	f(676, 778);
	f(670, 780);
	f(661, 780);
	f(657, 779);
	f(648, 777);
	f(642, 774);
	f(641, 772);
	f(641, 769);
	f(642, 765);
	glEnd(); // </ coin up
	glBegin(GL_POLYGON); // < coin down light
	glColor3fv(coin_luz);
	f(654,774);
	f(653,772 );
	f(665,775 );
	glEnd();// </ coin up light
	glBegin(GL_POLYGON);// < coin down
	glColor3fv(coin);
	f(654, 774);
	f(653, 772);
	f(644,768 );
	f(643,771 );
	f(648,773 );
	glEnd();// </ coin down dark
	glBegin(GL_LINE_STRIP);
	glColor3fv(black); // < costado izquierdo cuerpo
		f(507, 900);
		f(507, 871);
		f(508, 846);
		f(509, 828);
		f(510, 817);
		f(513, 800);
		f(515, 784);
		f(517, 773);
		f(521, 760);
		f(523, 753);
		f(525, 746);
		f(528, 740);
		f(536, 743);
		f(528, 740);
		f(531, 729);
		f(537, 715);
		f(541, 706);
		f(545, 698);
		f(549, 693);
		f(552, 688);
		f(555, 681);
	glEnd();// </ costado izquierdo cuerpo
	glBegin(GL_LINE_STRIP);// < oberol debajo brazo
		f(587, 752);
		f(597, 753);
		f(605, 755);
		f(612, 755);
		f(624, 756);
		f(624, 747);
		f(625, 738);
		f(644, 758);
		f(643, 761);
		f(642, 765);
		f(638, 765);
		f(630, 758);
		f(623, 757);
		f(621, 762);
		f(623, 765);
		f(627, 769);
	glEnd();
	glBegin(GL_LINE_STRIP);
		f(651, 807);
		f(653, 807);
		f(656, 806);
		f(658, 804);
		f(659, 801);
		f(663, 801);
		f(666, 800);
		f(669, 798);
		f(671, 801);
		f(674, 804);
		f(676, 804);
		f(679, 803);
		f(679, 801);
		f(679, 796);
		f(678, 793);
		f(683, 793);
		f(687, 794);
		f(690, 796);
		f(694, 800);
		f(718, 815);
		f(731, 823);
		f(745, 831);
		f(756, 837);
		f(767, 843);
		f(781, 850);
		f(794, 856);
		f(809, 862);
		f(820, 866);
		f(830, 870);
		f(840, 873);
		f(855, 877);
		f(868, 881);
		f(880, 884);
		f(892, 886);
		f(902, 887);
		f(914, 889);
		f(915, 900);
	glEnd();
	glBegin(GL_LINE_STRIP); // < moneda arriba
		f(642,765);
		f(644,768 );
		f(652,770 );
		f(657,772 );
		f(664,773 );
		f(669,774 );
		f(676,773 );
		f(676,778 );
		f(670,780 );
		f(661,780 );
		f(657,779 );
		f(648,777 );
		f(642,774 );
		f(641,772 );
		f(641,769 );
		f(642,765 );
	glEnd(); // </ moneda arriba
	//banda cafe
	glBegin(GL_LINE_STRIP);
		f(624,738);
		f(610,722);
		f(601,711);
		f(591,699 );
	glEnd();
	glBegin(GL_LINE_STRIP);
		f(626,710);
		f(639,725 );
		f(649,734 );
		f(686,766 );
		f(708,782 );
		f(720,790 );
		f(730,797 );
		f(748,808 );
		f(765,817 );
		f(777,824 );
		f(804,837 );
		f(826,845 );
		f(843,851 );
		f(863,857 );
		f(882,862 );
		f(897,866 );
		f(908,868 );
		f(915,869 );
		f(915,876 );
		f(914,889 );
	glEnd();
	glBegin(GL_LINE_STRIP);
		f(687,794);
		f(689,793 );
		f(690,791 );
		f(690,789 );
		f(690,787 );
		f(687,784 );
		f(684,782 );
		f(676,778 );
		f(676,775 );
		f(675,774 );
		f(677,772 );
		f(676,768 );
		f(674,765 );
		f(670,762 );
		f(665,760 );
		f(660,759 );
		f(654,758 );
		f(649,758 );
		f(645,759 );
	glEnd();
	/* Shirt*/
	glBegin(GL_LINE_STRIP);// < contorno brazo izquierdo
	glColor3fv(black);
	f(536, 728);
	f(536, 743);
	f(536, 752);
	f(537, 763);
	f(538, 773);
	f(540, 783);
	f(543, 794);
	f(547, 802);
	f(551, 811);
	f(559, 820);
	f(567, 826);
	f(575, 830);
	f(584, 831);
	f(595, 831);
	f(604, 828);
	f(621, 823);
	f(630, 819);
	f(637, 815);
	f(645, 811);
	f(651, 807);
	f(651, 798);
	f(643, 792);
	f(645, 795);
	f(641, 790);
	f(637, 797);
	f(634, 801);
	f(631, 802);
	f(629, 801);
	f(628, 800);
	f(628, 794);
	f(632, 784);
	f(632, 774);
	f(627, 769);
	f(619, 773);
	f(612, 774);
	f(603, 775);
	f(597, 774);
	f(594, 772);
	f(591, 769);
	f(588, 759);
	f(586, 752);
	f(583, 738);
	f(582, 729);
	f(582, 722);
	f(582, 717);
	f(581, 715);
	glEnd();// < contorno brazo derecho

	glBegin(GL_LINE_STRIP); // < segundo dedo
	f(641,791 );
	f(643,787 );
	f(647,784 );
	f(650,785 );
	f(651,786 );
	f(651,798 );
	glEnd(); // </ segundo dedo

	glBegin(GL_LINE_STRIP); // <tercer dedo
	f(659,801 );
	f(660,795 );
	f(661,790 );
	f(663,789 );
	f(664,789 );
	f(666,792 );
	f(669,798 );
	glEnd(); // </ tercer dedo

	glBegin(GL_LINE_STRIP); // cuarto/quinto dedo
	f(674,787 );
	f(678,793 );
	f(679,792 );
	f(674,787 );
	glEnd();

	glBegin(GL_LINE_STRIP);//backpack
	f(941,900 );
	f(941,892 );
	f(938,884 );
	f(934,874 );
	f(930,870 );
	f(924,866 );
	f(919,867 );
	f(918,868 );
	f(916,870 );
	glEnd();

	glBegin(GL_LINE_STRIP);
	f(945,900);
	f(945,895 );
	f(946,892 );
	f(946,886 );
	f(947,870 );
	f(940,856 );
	f(934,850 );
	f(928,848 );
	f(922,848 );
	f(916,850 );
	glEnd();

	//Rosa
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
	f(496, 448);
	f(491, 452);
	f(486, 455);
	f(481, 456);
	f(478, 458);
	f(475, 459);
	f(474, 459);
	f(472, 460);
	f(469, 461);
	f(465, 462);
	f(462, 463);
	f(458, 463);
	f(454, 463);
	f(453, 464);
	f(451, 464);
	f(449, 464);
	f(441, 465);
	f(452, 462);
	f(458, 458);
	f(463, 454);
	f(466, 450);
	f(474, 444);
	f(478, 440);
	f(480, 436);
	f(484, 433);
	f(485, 429);
	f(491, 421);
	f(495, 415);
	f(502, 403);
	f(508, 393);
	f(511, 388);
	f(517, 381);
	f(520, 378);
	f(521, 377);
	f(522, 376);
	f(523, 375);
	f(529, 370);
	f(532, 368); 
	f(538, 363);
	f(541, 361);
	f(545, 360);
	f(551, 356);
	f(557, 392);
	f(496, 448);
	glEnd();
	

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
	f(557, 392);
	f(557, 398);
	f(557, 403);
	f(556, 408);
	f(556, 414);
	f(555, 417); 
	f(554, 421);
	f(553, 431);
	f(552, 437);
	f(551, 441);
	f(550, 445);
	f(549, 451);
	f(548, 456);
	f(547, 460);
	f(546, 463);
	f(545, 465);
	f(544, 471);
	f(543, 474);
	f(542, 476);
	f(540, 479);
	f(539, 481);
	f(534, 491);
	f(532, 494);
	f(531, 496);
	f(530, 497);
	f(529, 500);
	f(527, 501);
	f(526, 504);
	f(524, 507);
	f(522, 510);
	f(521, 511);
	f(519, 513);
	f(518, 514);
	f(517, 516);
	f(515, 516);
	f(514, 517);
	f(513, 518);
	f(510, 522);
	f(507, 523);
	f(505, 526);
	f(501, 528);
	f(502, 529);
	f(500, 529);
	f(499, 531);
	f(494, 534);
	f(492, 535);
	f(490, 536);
	f(488, 538);
	f(484, 539);
	f(482, 541);
	f(479, 542);
	f(474, 544);
	f(473, 544);
	f(473, 538);
	f(473, 535);
	f(472, 527);
	f(471, 523);
	f(472, 511);
	f(472, 507);
	f(473, 502);
	f(472, 498);
	f(473, 490);
	f(474, 484);
	f(475, 480);
	f(475, 479);
	f(476, 476);
	f(476, 472);
	f(477, 468);
	f(478, 465);
	f(478, 462);
	f(479, 459);
	f(481, 456);
	f(486, 455);
	f(491, 452);
	f(496, 448);
	f(557, 392);

	glEnd();
	
	//line hair
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_LINE_STRIP);
	glColor3fv(black);
	f(496, 448);
	f(491, 452);
	f(486, 455);
	f(481, 456);
	f(478, 458);
	f(475, 459);
	f(474, 459);
	f(472, 460);
	f(469, 461);
	f(465, 462);
	f(462, 463);
	f(458, 463);
	f(454, 463);
	f(453, 464);
	f(451, 464);
	f(449, 464);
	f(441, 465);
	f(452, 462);
	f(458, 458);
	f(463, 454);
	f(466, 450);
	f(474, 444);
	f(478, 440);
	f(480, 436);
	f(484, 433);
	f(485, 429);
	f(491, 421);
	f(495, 415);
	f(502, 403);
	f(508, 393);
	f(511, 388);
	f(517, 381);
	f(520, 378);
	f(521, 377);
	f(522, 376);
	f(523, 375);
	f(529, 370);
	f(532, 368);
	f(538, 363);
	f(541, 361);
	f(545, 360);
	f(551, 356);
	f(552, 356);
	f(554, 355);
	f(556, 355);
	f(556, 354);
	f(558, 353);
	f(560, 353);
	f(562, 352);
	f(565, 351);
	f(567, 350);
	f(571, 349);
	f(575, 348);
	f(576, 348);
	f(578, 347);
	f(579, 347);
	f(581, 347);
	f(582, 346);
	f(584, 346);
	f(585, 345);
	f(587, 344);
	f(590, 344);
	f(593, 343);
	f(595, 342);
	f(598, 341);
	f(599, 341);
	f(602, 340);
	f(605, 339);
	f(608, 338);
	f(610, 338);
	f(614, 337);
	f(616, 337);
	f(619, 336);
	f(622, 335);
	f(624, 335);
	f(628, 334);
	f(632, 334);
	f(634, 333);
	f(640, 333);
	f(641, 332);
	f(646, 331);
	f(651, 331);
	f(655, 330);
	f(657, 329);
	f(659, 329);
	f(661, 329);
	f(669, 328);
	f(676, 327);
	f(681, 327);
	f(685, 326);
	f(690, 326);
	f(692, 325);
	f(696, 325);
	f(700, 325);
	f(706, 324);
	f(720, 324);
	f(721, 323);
	f(740, 323);
	f(741, 322);
	f(763, 322);
	f(786, 322);
	f(787, 323);
	f(803, 323);
	f(804, 324);
	f(809, 324);
	f(810, 325);
	f(818, 325);
	f(819, 326);
	f(822, 326);
	f(823, 327);
	f(828, 327);
	f(829, 328);
	f(833, 329);
	f(834, 329);
	f(838, 329);
	f(839, 330);
	f(841, 331);
	f(846, 332);
	f(852, 334);
	f(855, 335);
	f(859, 337);
	f(862, 339);
	f(868, 342);
	f(871, 344);
	f(873, 346);
	f(877, 350);
	f(891, 365);
	f(913, 382);
	f(923, 387);
	f(922, 386);
	f(931, 388);
	f(929, 390);
	f(914, 394);
	f(910, 393);
	f(904, 389);
	f(919, 400);
	f(925, 403);
	f(934, 406);
	f(929, 410);
	f(913, 413);
	f(917, 419);
	f(924, 434);
	f(931, 456);
	f(936, 483);
	f(904, 465);
	f(885, 449);
	f(873, 438); 
	f(858, 419);
	f(831, 370); 
	f(834, 376);
	f(827, 391);
	f(825, 403);


	f(814, 387); 
	f(812, 379);
	f(811, 368);
	f(812, 382);
	f(813, 389);
	f(818, 406);
	f(826, 422);
	f(792, 413);
	f(772, 403);
	f(752, 390);
	f(734, 369);
	f(731, 366);

	f(734, 369);
	f(733, 381);
	f(734, 393);
	f(740, 407);
	f(755, 434);
	f(730, 426);
	f(704, 410);
	f(673, 373);
	f(668, 366);

	f(673, 373);
	f(674, 384);
	f(678, 393);
	f(686, 410);
	f(695, 423);
	f(711, 447);
	f(680, 440);
	f(673, 438);
	f(649, 426);
	f(636, 419);
	f(621, 409);
	f(595, 385);

	f(594, 378);
	f(595, 385);
	f(592, 394);
	f(590, 405);
	f(583, 423);
	f(566, 447);
	f(563, 407);
	f(557, 396);

	f(557, 392);
	f(557, 398);
	f(557, 403);
	f(556, 408);
	f(556, 414);
	f(555, 417);
	f(554, 421);
	f(553, 431);
	f(552, 437);
	f(551, 441);
	f(550, 445);
	f(549, 451);
	f(548, 456);
	f(547, 460);
	f(546, 463);
	f(545, 465);
	f(544, 471);
	f(543, 474);
	f(542, 476);
	f(540, 479);
	f(539, 481);
	f(534, 491);
	f(532, 494);
	f(531, 496);
	f(530, 497);
	f(529, 500);
	f(527, 501);
	f(526, 504);
	f(524, 507);
	f(522, 510);
	f(521, 511);
	f(519, 513);
	f(518, 514);
	f(517, 516);
	f(515, 516);
	f(514, 517);
	f(513, 518);
	f(510, 522);
	f(507, 523);
	f(505, 526);
	f(501, 528);
	f(502, 529);
	f(500, 529);
	f(499, 531);
	f(494, 534);
	f(492, 535);
	f(490, 536);
	f(488, 538);
	f(484, 539);
	f(482, 541);
	f(479, 542);
	f(474, 544);
	f(473, 544);
	f(473, 538);
	f(473, 535);
	f(472, 527);
	f(471, 523);
	f(472, 511);
	f(472, 507);
	f(473, 502);
	f(472, 498);
	f(473, 490);
	f(474, 484);
	f(475, 480);
	f(475, 479);
	f(476, 476);
	f(476, 472);
	f(477, 468);
	f(478, 465);
	f(478, 462);
	f(479, 459);
	glEnd();

	//face line
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_LINE_STRIP);
	glColor3fv(black);
	f(473, 544);
	f(478, 568);
	f(490, 603);
	f(500, 622);
	f(518, 648);
	f(554, 680);
	f(564, 687);
	f(593, 700);
	f(623, 710);
	f(653, 723);


	
	
	glEnd();

	glFlush();
}
 
void reshape ( int width , int height )   // Creamos funcion Reshape
{
	if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	glOrtho(0,1600,900,0,0.1,2);//COORDENADAS

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	 glutPostRedisplay();
}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 480)
	{
		boca_open = !boca_open;
		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (1600*.9, 900*.9);	// Tama�o de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Greg"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut funci�n de manejo de teclado
  glutIdleFunc		  (animacion);
  glutMainLoop        ( );          // 

  return 0;
}