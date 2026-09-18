 

#include <iostream>
using namespace std;

enum enOperationType { Add = 1, sub = 2, Mul = 3, Div = 4, Mixop = 5 };
enum enQuestionLevel {Easy = 1, Mid = 2, Hard = 3, MixQ = 4};

struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
	enOperationType OperationType;
	enQuestionLevel QuestionLevel;
};

struct stQuizz
{
	stQuestion QuestionList[100];
	short NumberOfQuestions = 0;
	enOperationType OpType;
	enQuestionLevel QuesLevel;
	short NumberOfWrongAnswers = 0;
	short NumberOfRightAnswers = 0;
	bool IsPass = false;
};

int ReadHowManyQuestions()
{
	int NumberOfQuestions = 0;
	do
	{
		cout << "\nEnter How Many Questions ? ";
		cin >> NumberOfQuestions;
	} while (NumberOfQuestions < 1 || NumberOfQuestions > 10);
	return  NumberOfQuestions;
}

enQuestionLevel ReadQuestionLevel()
{
	int QuestionType = 1;
	do
	{
		cout << "\nEnter Question Level ,[1] Easy ,[2] Mid ,[3] Hard ,[4] MixOp ? ";
		cin >> QuestionType;
	} while (QuestionType < 1 || QuestionType > 5);

	return (enQuestionLevel)QuestionType;
}

enOperationType ReadOpertionType() {
	int QuestionLevel = 1;
	do
	{
		cout << "\nEnter Question Type ,[1] Add,[2] Sub,[3] Mul,[4] Div,[5] MixOp ? ";
		cin >> QuestionLevel;
	} while (QuestionLevel < 1 || QuestionLevel > 5);

	return (enOperationType)QuestionLevel;
}

string GerQuestionLevelText(enQuestionLevel QuestionLevel)
{
	string QuestionLevelArray[4] = { "Easy" , "Midium", "Hard", "Mix" };

	return QuestionLevelArray[QuestionLevel - 1];
}

int GenerateRandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

int SimpleCalculator(int Number1,int Number2, enOperationType Op)
{
	switch (Op)
	{
	case enOperationType::Add:
		return Number1 + Number2;

	case enOperationType::sub:
		return Number1 - Number2;
		
	case enOperationType::Div:
		return Number1 / Number2;

	case enOperationType::Mul:
		return Number1 * Number2;

	default:
		return Number1 + Number2;
		
	}
}

string GetOpTypeSymbol(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return "+";
		case enOperationType::sub:
		return "-";
	case enOperationType::Mul:
		return "x";
	case enOperationType::Div:
		return "/";
	default:
		return "Mix";
	}
}

void PrintTheQuestion(stQuizz& Quizz,int i)
{
	cout << "\n";
	cout << "[Question " << i + 1 << "/" << Quizz.NumberOfQuestions << "]\n\n";
	cout << Quizz.QuestionList[i].Number1 << endl;
	cout << Quizz.QuestionList[i].Number2 << " ";
	cout << GetOpTypeSymbol(Quizz.QuestionList[i].OperationType) << endl;
	cout << "\n--------\n";
	
}

int ReadPlayerAnswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short NumberOfQuizz)
{
	if (Quizz.QuestionList[NumberOfQuizz].PlayerAnswer != Quizz.QuestionList[NumberOfQuizz].CorrectAnswer)
	{
		Quizz.NumberOfWrongAnswers++;
		Quizz.QuestionList[NumberOfQuizz].AnswerResult = false;
		cout << "\nWrong Answer :-(\n";
		cout << "\nThe Right Answer Is " << Quizz.QuestionList[NumberOfQuizz].CorrectAnswer;
		cout << "\n";
	}
	else
	{
		Quizz.QuestionList[NumberOfQuizz].AnswerResult = true;
		Quizz.NumberOfRightAnswers++;
		cout << "\nRight Answer (-:\n";
	}
	cout << endl;
}

enOperationType GenerateRandomOperationType()
{
	int op = GenerateRandomNumber(1, 4);
	
	return (enOperationType)op;
}

void AskAndCorrectQuestionListAnswer(stQuizz& Quizz) {

	for (int i = 0; i < Quizz.NumberOfQuestions; i++)
	{
		PrintTheQuestion(Quizz, i);
		Quizz.QuestionList[i].PlayerAnswer = ReadPlayerAnswer();
		CorrectTheQuestionAnswer(Quizz,i);
	}

	Quizz.IsPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}

stQuestion GenerateQuestion(enQuestionLevel QuesLevel,enOperationType OpType)
{
	stQuestion Question;

	if (QuesLevel == enQuestionLevel::MixQ)
	{
		QuesLevel = (enQuestionLevel)GenerateRandomNumber(1, 3);
	}

	if (OpType == enOperationType::Mixop)
	{
		OpType = GenerateRandomOperationType();
	}

	Question.OperationType = OpType;

	switch (QuesLevel)
	{
	case Easy:
		Question.Number1 = GenerateRandomNumber(1, 10);
		Question.Number2 = GenerateRandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuesLevel;
		return Question;

	case Mid:
		Question.Number1 = GenerateRandomNumber(10, 50);
		Question.Number2 = GenerateRandomNumber(10, 50);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuesLevel;
		return Question;

	case Hard:
		Question.Number1 = GenerateRandomNumber(50, 100);
		Question.Number2 = GenerateRandomNumber(50, 100);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuesLevel;
		return Question;
	}
	return Question;
}

void GenerateQuizzQuestions(stQuizz& Quizz)
{
	for (int i = 0; i < Quizz.NumberOfQuestions; i++)
	{
		Quizz.QuestionList[i] = GenerateQuestion(Quizz.QuesLevel, Quizz.OpType);
	}
}

string GetFinalResultText(bool Pass)
{
	if (Pass)
	{
		return "Pass (-:";
	}
	else
	{
		return "Fail :-)";
	}
}

void PrintFinalQuizzResult(stQuizz Quizz) 
{
	cout << "\n----------------------------------\n\n";
	cout << "Final Result Is " << GetFinalResultText(Quizz.IsPass);
	cout << "\n----------------------------------\n\n";
	cout << "Number Of Quesions = " << Quizz.NumberOfQuestions << endl;
	cout << "Number Level = " <<  GerQuestionLevelText(Quizz.QuesLevel) << endl;
	cout << "Operation Type = " << GetOpTypeSymbol(Quizz.OpType) << endl;
	cout << "Number Of Right Answers = " << Quizz.NumberOfRightAnswers << endl;
	cout << "Number Of Wrong Answers = " << Quizz.NumberOfWrongAnswers << endl;
	cout << "\n----------------------------------\n\n";

}

void PlayMathGame()
{
	stQuizz Quizz;
	Quizz.NumberOfQuestions = ReadHowManyQuestions();
	Quizz.QuesLevel  = ReadQuestionLevel();
	Quizz.OpType = ReadOpertionType();

	GenerateQuizzQuestions(Quizz);
	AskAndCorrectQuestionListAnswer(Quizz);
	PrintFinalQuizzResult(Quizz);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		PlayMathGame();

		cout << endl << "Do You Want To Play Again(Y/N)?";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}

 