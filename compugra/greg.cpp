//Semestre 2017 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Augusto Meza Peña				        ******//
//*************	Muñoz Alvarez Rosa Maria Yolotzin		******//
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
	glLineWidth(3.0);


	//Augusto
	/*			Tetera		*/
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
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
	glEnd();
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
	glBegin(GL_LINE_STRIP);
	glColor3fv(black);
	f(978, 300);
	f(980, 297);
	f(985, 297);
	f(997, 302);
	f(1005, 306);
	f(1000, 307);
	f(993, 306);
	f(985, 303);
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
	glColor3f(tetera_luz[0], tetera_luz[1], tetera_luz[2]);
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
	glColor3f(tetera_luz[0], tetera_luz[1], tetera_luz[2]);
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
	/*			gooooooo*/
	glBegin(GL_LINE_STRIP);
		glColor3fv(black);
		f(850, 135);
		f(850, 135);
		f(850, 140);
	glEnd();

	//Rose
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
	glColor3fv(skin);
		f(473, 544);
		f(557, 392);
		f(668, 366);
		f(831, 370);
		f(936, 483);
	glEnd();

	//left ear fill
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(skin);
	f(472, 535);
	f(465, 534);
	f(460, 535);
	f(456, 538);
	f(449, 541);
	f(473, 544);
	f(478, 568);
	f(497, 617);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(skin);
	f(473, 544);
	f(449, 541);
	f(465, 534);
	f(460, 535);
	f(456, 538);
	f(449, 541);
	f(437, 557);
	f(435, 567);
	f(435, 580);
	f(442, 596);
	f(453, 609);
	f(490, 603);
	f(478, 568);
	glEnd();


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(skin);
	f(490, 603);
	f(453, 609);
	f(462, 614);
	f(470, 618);
	f(481, 620);
	f(489, 620);
	f(497, 617);
	glEnd();



	//hair fill
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//left part
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

	//first fringe.
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
		f(594, 378);
		f(595, 385);
		f(592, 394);
		f(590, 405);
		f(583, 423);
		f(566, 447);
		f(563, 407);
		f(557, 396);
		f(557, 392);
	glEnd();

	//second fringe
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//second
	glBegin(GL_POLYGON);
	glColor3fv(hair);
		f(686, 410);
		f(695, 423);
		f(711, 447);//tip
		f(680, 440);
		f(673, 438);
		f(649, 426);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
		f(668, 366);
		f(673, 373);
		f(674, 384);
		f(678, 393);
		f(686, 410);
		f(649, 426);
		f(636, 419);
		f(621, 409);
		f(595, 385);
		f(594, 378);
	glEnd();

	//third fringe
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
		f(734, 393);
		f(740, 407);
		f(755, 434);//tip
		f(730, 426);
		f(704, 410);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
		f(731, 366);
		f(734, 369);
		f(733, 381);
		f(734, 393);
		f(704, 410);
		f(673, 373);
		f(668, 366);
	glEnd();
	
	//4th fringe
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
		f(813, 389);
		f(818, 406);
		f(826, 422);//tip
		f(792, 413);
		f(772, 403);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
		f(811, 368);
		f(812, 382);
		f(813, 389);
		f(772, 403);
		f(752, 390);
		f(734, 369);
		f(731, 366);
	glEnd();

	//5th fringe
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
		f(831, 370);
		f(834, 376);
		f(827, 391);
		f(825, 403);
		f(814, 387);
		f(812, 379);
		f(811, 368);
	glEnd();

	//right part
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
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
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//down fringe
	glBegin(GL_POLYGON);
	glColor3fv(hair);
		f(904, 389);
		f(919, 400);
		f(925, 403);
		f(934, 406);
		f(929, 410);
		f(913, 413);
	glEnd();


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//upper fringe
	glBegin(GL_POLYGON);
	glColor3fv(hair);
		f(907, 379);
		f(913, 382);
		f(923, 387);
		f(922, 386);
		f(931, 388);//pico cabello
		f(929, 390);
		f(914, 394);
		f(910, 393);
		f(904, 389);
	glEnd();

	//filling all
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
		f(831, 370);
		f(904, 389);
		f(913, 413);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
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
		f(907, 379);
		f(913, 413);
		f(904, 389);
		f(831, 370);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
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
		f(831, 370);
		f(811, 368);
	
	glEnd();
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
		f(720, 324);
		f(721, 323);
		f(740, 323);
		f(741, 322);
		f(763, 322);
		f(786, 322);
		f(787, 323);
		f(803, 323);
		f(804, 324);
		f(811, 368);
		f(731, 366);

	glEnd();
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
		f(731, 366);
		f(668, 366);
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
		f(803, 323);
	glEnd();
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
		f(668, 366);
		f(594, 378);
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

	glEnd();

	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(hair);
		f(594, 378);
		f(557, 392);
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

	glEnd();
	
	//hair line
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
		f(913, 382);//after up
		f(923, 387);
		f(922, 386);
		f(931, 388);//tip
		f(929, 390);
		f(914, 394);
		f(910, 393);
		f(904, 389);//tip
		f(919, 400);
		f(925, 403);
		f(934, 406);//tip
		f(929, 410);
		f(913, 413);
		f(917, 419);
		f(924, 434);
		f(931, 456);
		f(936, 483);//tip
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

	//face fill
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(skin);
	f(473, 544);
	f(478, 568);
	f(490, 603);
	f(500, 622);
	f(518, 648);
	f(541, 670);
	f(571, 690);
	f(591, 700);
	f(610, 706);
	f(630, 711);
	f(650, 716);
	f(682, 718);
	f(732, 720);
	f(729, 561);
	f(473, 544);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(skin);
	
	f(732, 720);
	f(749, 718);
	f(761, 717);
	f(790, 710);
	f(806, 706);
	f(843, 690);
	f(880, 666);
	f(900, 647);
	f(916, 626);
	f(929, 597);
	f(938, 557);
	f(940, 516);
	f(936, 483);
	f(729, 561);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(skin);
	f(473, 544);
	f(729, 561);
	f(936, 483);
	glEnd();


	//right ear fill
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(skin);
		f(938, 496);
		f(946, 494);
		f(957, 495);
		f(965, 500);
		f(969, 504);
		f(940, 516);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(skin);
	f(938, 496);
	f(946, 494);
	f(957, 495);
	f(965, 500);
	f(969, 504);
	f(940, 516);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(skin);
		f(940, 516);
		f(969, 504);
		f(969, 504);
		f(978, 517);
		f(980, 523);
		f(982, 532);
		f(980, 547);
		f(976, 557);
		f(971, 565);
		f(964, 572);
		f(951, 582);
		f(938, 557);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3fv(skin);
		f(951, 582);
		f(938, 557);
		f(932, 588);
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
		f(541, 670);
		f(571, 690);
		f(591, 700);
		f(610, 706);
		f(630, 711);
		f(650, 716);
		f(682, 718);
		f(732, 720);
		f(749, 718);
		f(761, 717);
		f(790, 710);
		f(806, 706);
		f(843, 690);
		f(880, 666);
		f(900, 647);
		f(916, 626);
		f(929, 597);
		f(938, 557);
		f(940, 516);
		f(936, 483);
	glEnd();

	

	//right ear line
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_LINE_STRIP);
	glColor3fv(black);
		f(938, 496);
		f(946, 494);
		f(957, 495);
		f(965, 500);
		f(969, 504);
		f(978, 517);
		f(980, 523);
		f(982, 532);
		f(980, 547);
		f(976, 557);
		f(971, 565);
		f(964, 572);
		f(951, 582);
		f(932, 588);

	glEnd();

	//left ear line
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_LINE_STRIP);
	glColor3fv(black);
		f(472, 535);
		f(465, 534);
		f(460, 535);
		f(456, 538);
		f(449, 541);
		f(437, 557);
		f(435, 567);
		f(435, 580);
		f(442, 596);
		f(453, 609);
		f(462, 614);
		f(470, 618);
		f(481, 620);
		f(489, 620);
		f(497, 617);
	
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
  glutInitWindowSize  (1600, 900);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Greg"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutIdleFunc		  (animacion);
  glutMainLoop        ( );          // 

  return 0;
}