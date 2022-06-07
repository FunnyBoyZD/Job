#define _CRT_SECURE_NO_WARNINGS
#include "locale.h"
#include "windows.h"
#include <iostream>

int workWithFileAndPrint(char* chapter);
int numberScan(int& N);

int main()
{
	int workWithDON = 0;
	char* chapter = NULL;

	SetConsoleCP(1251); //підключення кирилиці
	SetConsoleOutputCP(1251);

	if (!(chapter = new char[64]))
	{
		std::cout << "Не вдалося виділити пам'ять під рядок задля запису назви розділу!" << std::endl;
		return -1;
	}

	std::cout << "===========================================Довідник нумізмата: усе про монети===========================================" << std::endl;
	std::cout << "1)Нумізматика - наука про монети" << std::endl;
	std::cout << "Нумізматика - наука про монети. Це допоміжна історична дисципліна, що вивчає історію монетного карбування та грошового" << std::endl <<
		"обігу.В основі цього слова лежить грецьке іменник номос(nomos) - закон, іншими словами - законний платіжний засіб - і " << std::endl <<
		"похідний від нього номізму(nomisma) - монета. Далі можна детальніше дізнатися про те, що таке нумізматика," << std::endl <<
		"ознайомившись із докладними відомостями з ВВЕ, Брокгауза та Ефрона та інших довідників та словників." << std::endl;
	std::cout << "*****************Для того, щоб докладніше ознайомитися з цим розділом, введіть 1 після переліку всіх розділів довідника!" << std::endl << std::endl << std::endl;

	std::cout << "2)Що таке монета" << std::endl;
	std::cout << "Монета — зливок металу певної форми, ваги, проби та гідності, що є узаконеним засобом обігу. Назва монета походить від" << std::endl <<
		"імені богині Юнони Монети, при храмі якої почали карбуватися металеві гроші.Вони стали називатися в Римі, а згодом і в" << std::endl <<
		"інших країнах монетами.Про те, що таке монета, можна дізнатися, ознайомившись з різних довідників та словників з" << std::endl<<
		"детальними відомостями про цей злив металу, що володіє загадковою привабливою силою. " << std::endl;
	std::cout << "*****************Для того, щоб докладніше ознайомитися з цим розділом, введіть 2 після переліку всіх розділів довідника!" << std::endl << std::endl << std::endl;

	std::cout << "3)Класифікація монет за ступенем збереження" << std::endl;
	std::cout << "У Європі переважно використовується 8-позиційна шкала, з невеликими варіаціями у різних країнах. Американська" << std::endl <<
		"Нумізматична Асоціація використовує 70 - бальну шкалу, розроблену професором В.Шелдоном. Тут — про всі європейські та" << std::endl<<
		"американські системи класифікації, а також про найтонші нюанси визначення якості монет." << std::endl;
	std::cout << "*****************Для того, щоб докладніше ознайомитися з цим розділом, введіть 3 після переліку всіх розділів довідника!" << std::endl << std::endl << std::endl;

	std::cout << "4)Українська класифікація монет за якістю та збереженням" << std::endl;
	std::cout << "Про українську систему класифікації категорій якості карбування та стану збереження колекційної нумізматичної" << std::endl <<
		"продукції. Її порівняння з англійською класифікацією." << std::endl;
	std::cout << "*****************Для того, щоб докладніше ознайомитися з цим розділом, введіть 4 після переліку всіх розділів довідника!" << std::endl << std::endl << std::endl;

	std::cout << "5)Матеріали задля виготовлення монет" << std::endl;
	std::cout << "Матеріали виготовлення монет — різні метали та його сплави. Тут можна дізнатися і про звичайні, і про найекзотичніші" << std::endl << 
		"матеріали, з яких у різні часи карбувалися монети, як, наприклад, Акмонітал, Аргентан, Ауріхалк, Віреніум, Дзвоновий" << std::endl <<
		"і Гарматний метал, Коронне золото, Нейзільбер, Нордгельд, Нордік, Пінчбек, П'ютер , Спекулум, Томпак, і т.д., і т.п." << std::endl;
	std::cout << "*****************Для того, щоб докладніше ознайомитися з цим розділом, введіть 5 після переліку всіх розділів довідника!" << std::endl << std::endl << std::endl;

	std::cout << "6)Проба металу, з якого роблять монети" << std::endl;
	std::cout << "Проба - це вміст чистого дорогоцінного металу в металі, з якого карбуються монети. Застосовуються метрична та каратна" << std::endl <<
		"системи проб.У Росії її до 1927 року застосовувалася золотникова система проб. Водночас тут наводяться правила" << std::endl <<
		"перерахунку з однієї системи в іншу, а також склади найвідоміших золотих сплавів : дукатного золота, кронового золота," << std::endl << 
		"пістольного золота." << std::endl;
	std::cout << "*****************Для того, щоб докладніше ознайомитися з цим розділом, введіть 6 після переліку всіх розділів довідника!" << std::endl << std::endl << std::endl;

	std::cout << "7)Як роблять монети" << std::endl;
	std::cout << "Процес починається зі створення тривимірної дизайнерської моделі, розміри якої більші, ніж у реальної монети. За"<< std::endl << 
		"допомогою спеціальної машини, що редукує, зображення з позитиву переносять на сталевий майстер - штамп, розміри якого" << std::endl << 
		"відповідають розмірам монети. Детальна розповідь про сучасну технологію виготовлення монет з ілюстраціями..." << std::endl;
	std::cout << "*****************Для того, щоб докладніше ознайомитися з цим розділом, введіть 7 після переліку всіх розділів довідника!" << std::endl << std::endl << std::endl;

	for(;;)
	{
		std::cout << "Введіть номер опції для подальшої роботи з програмою:" << std::endl <<
			"1)Ознайомитись докладніше з розділом 1;" << std::endl <<
			"2)Ознайомитись докладніше з розділом 2;" << std::endl <<
			"3)Ознайомитись докладніше з розділом 3;" << std::endl <<
			"4)Ознайомитись докладніше з розділом 4;" << std::endl <<
			"5)Ознайомитись докладніше з розділом 5;" << std::endl <<
			"6)Ознайомитись докладніше з розділом 6;" << std::endl <<
			"7)Ознайомитись докладніше з розділом 7;" << std::endl <<
			"8)Завершити роботу з програмою;" << std::endl;
		numberScan(workWithDON); //зчитування пункту меню
		switch (workWithDON)
		{
		case 1:
		{
			strcpy(chapter, "Нумізматика - наука про монети");
			workWithFileAndPrint(chapter);
			break;
		}
		case 2:
		{
			strcpy(chapter, "Що таке монета");
			switch (workWithFileAndPrint(chapter))
			{
			case -1:
			{
				return -1;
			}
			case -2:
			{
				return -2;
			}
			case -3:
			{
				std::cout << "Не вдалося перемістити покажчик у файлі на початок" << std::endl;
				return -3;
			}
			}
			break;
		}
		case 3:
		{
			strcpy(chapter, "Класифікація монет за ступенем збереження");
			switch (workWithFileAndPrint(chapter))
			{
			case -1:
			{
				return -1;
			}
			case -2:
			{
				return -2;
			}
			case -3:
			{
				std::cout << "Не вдалося перемістити покажчик у файлі на початок" << std::endl;
				return -3;
			}
			}
			break;
		}
		case 4:
		{
			strcpy(chapter, "Українська класифікація монет за якістю та збереженням");
			switch (workWithFileAndPrint(chapter))
			{
			case -1:
			{
				return -1;
			}
			case -2:
			{
				return -2;
			}
			case -3:
			{
				std::cout << "Не вдалося перемістити покажчик у файлі на початок" << std::endl;
				return -3;
			}
			}
			break;
		}
		case 5:
		{
			strcpy(chapter, "Матеріали задля виготовлення монет");
			switch (workWithFileAndPrint(chapter))
			{
			case -1:
			{
				return -1;
			}
			case -2:
			{
				return -2;
			}
			case -3:
			{
				std::cout << "Не вдалося перемістити покажчик у файлі на початок" << std::endl;
				return -3;
			}
			}
			break;
		}
		case 6:
		{
			strcpy(chapter, "Проба металу, з якого роблять монети");
			switch (workWithFileAndPrint(chapter))
			{
			case -1:
			{
				return -1;
			}
			case -2:
			{
				return -2;
			}
			case -3:
			{
				std::cout << "Не вдалося перемістити покажчик у файлі на початок" << std::endl;
				return -3;
			}
			}
			break;
		}
		case 7:
		{
			strcpy(chapter, "Як роблять монети");
			switch (workWithFileAndPrint(chapter))
			{
			case -1:
			{
				return -1;
			}
			case -2:
			{
				return -2;
			}
			case -3:
			{
				std::cout << "Не вдалося перемістити покажчик у файлі на початок" << std::endl;
				return -3;
			}
			}
			break;
		}
		case 8:
		{
			std::cout << "=========================================Дякую за використання нашої програми!==========================================" << std::endl;
			delete[] chapter;
			return 0;
		}
		default:
		{
			std::cout << "Ви ввели некоректне значення, спробуйте ще раз!" << std::endl << std::endl;
			continue;
			break;
		}
		}
	}

}

/*
Функція введення значень змінних
Вхід:
	N - адреса змінної для ініціалізації
Вихід:
	numberScan = N - ініціалізована змінна
*/
int numberScan(int& N) {
	int entered = 0; //змінна для контролю введених користувачем з клавіатури символів
	do {
		do {
			entered = scanf_s("%d", &N);
			while (getchar() != '\n');
			while (entered < 1) {
				printf("Ви ввели некоректне значення, повторіть введення: ");
				entered = scanf_s("%d", &N);
				while (getchar() != '\n');
			}
		} while (entered < 1);
	} while (entered != 1);
	return N;
}

/*
Функція зчитування інформації з файлу та виведення на екран потрібного розділу
Вхід:
	chapterName - рядок з назвою розділу
Вихід:
	workWithFileAndPrint = 0 - функція виконана успішно
						 = -1 - не вдалося виділити пам'ять під рядок
						 = -2 - не вдалося відкрити файл DON.txt
						 = -3 - не вдалося перемістити покажчик у файлі на початок
*/
int workWithFileAndPrint(char* chapterName)
{
	FILE* fd = NULL;
	char* toCopy = NULL,
		* neededInformation = NULL,
		* allInformation = NULL,
		* toFind = NULL,
		* symbol = NULL;

	if (!(toCopy = new char[128]))
	{
		std::cout << "Не вдалося виділити пам'ять під рядок задля розміщення тексту з файлу!" << std::endl;
		return -1;
	}

	if (!(neededInformation = new char[16384]))
	{
		std::cout << "Не вдалося виділити пам'ять під рядок задля розміщення тексту з файлу!" << std::endl;
		return -1;
	}	
	if (!(allInformation = new char[65536]))
	{
		std::cout << "Не вдалося виділити пам'ять під рядок задля розміщення тексту з файлу!" << std::endl;
		return -1;
	}

	if (!(toFind = new char[64]))
	{
		std::cout << "Не вдалося виділити пам'ять під рядок задля розміщення заголовку розділу!" << std::endl;
		return -1;
	}

	if (!(symbol = new char))
	{
		std::cout << "Не вдалося виділити пам'ять під рядок задля розміщення символів!" << std::endl;
		return -1;
	}

	if ((fd = fopen("DON.txt", "r")) == NULL)
	{
		std::cout << "Не вдалося відкрити файл DON.txt!" << std::endl;
		return -2;
	}

	(void)fscanf(fd, "%s", toCopy);
	toCopy[strlen(toCopy) + 1] = '\0';
	strcpy(allInformation, toCopy);

	while (!feof(fd))
	{
		strcat(allInformation, " ");
		(void)fscanf(fd, "%s", toCopy);
		(void)fscanf(fd, "%c", symbol);
		strcat(allInformation, toCopy);
		if (symbol[0] == '\n')
		{
			strcat(allInformation, "\n");
		}
	}
	rewind(fd);
	if (ferror(fd))
	{
		return -3;
	}

	for (int i = 0;;i++)
	{
		if (allInformation[i] == '[')
		{
			for (int j = i + 1, w = 0;allInformation[j] != ']';j++, w++)
			{
				toFind[w] = allInformation[j];
				if (allInformation[j + 1] == ']')
				{
					toFind[w + 1] = '\0';
				}
			}
			if (strcmp(toFind, chapterName) == 0)
			{
				for (int j = i, w = 0;;j++, w++)
				{
					if (i + 128 - j < 0)
					{
						if (allInformation[j + 2] == '[' || allInformation[j] == '\0')
						{
							break;
						}
						else
						{
							neededInformation[w] = allInformation[j];
							neededInformation[w + 1] = '\0';
						}
					}
					else
					{
						neededInformation[w] = allInformation[j];
						neededInformation[w + 1] = '\0';
					}
				}
				break;
			}
			else
			{
				delete[] toFind;
				if (!(toFind = new char[64]))
				{
					std::cout << "Не вдалося виділити пам'ять під рядок задля розміщення заголовку розділу!" << std::endl;
					return -1;
				}
			}
		}
	}
	
	for (int i = 0; neededInformation[i + 1] != '\0';i++)
	{
		std::cout << neededInformation[i];
	}
	std::cout << std::endl << std::endl << std::endl;

	delete[] toCopy;
	delete[] neededInformation;
	delete[] allInformation;
	delete[] toFind;
	delete symbol;
	fclose(fd);
	return 0;
}