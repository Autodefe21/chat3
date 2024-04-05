#include "User.h"
#include "Chat.h"
#include <iostream>
#include <locale.h>
#include <memory>

std::vector<std::shared_ptr<User>> users;

void clearConsole()
{
#ifdef _WIN32
    system("cls");
#endif
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Chat chat;
    std::shared_ptr<User> user = std::make_shared<User>();
    std::shared_ptr<Message> message = std::make_shared<Message>();
    int choice;
    int choice1{};

    while (true) {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Регистрация нового пользователя" << std::endl;
        std::cout << "2. Вход в аккаунт" << std::endl;
        std::cout << "0. Выйти из программы" << std::endl;

        std::cout << "Введите номер выбранного действия: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::string username, password;
            std::cout << "Введите имя пользователя: ";
            std::cin >> username;
            std::cout << "Введите пароль: ";
            std::cin >> password;
            chat.registerUser(username, password);
            break;
        }
        case 2: {
            std::string userName, password;
            std::cout << "Введите имя пользователя: ";
            std::cin >> userName;
            std::cout << "Введите пароль: ";
            std::cin >> password;
            bool loginSuccess = chat.login(userName, password);
            if (loginSuccess) {
                std::cout << "Вход в аккаунт прошел успешно." << std::endl;
                while (true) {
                    std::vector<std::shared_ptr<Message>> messages = chat.getMessage();
                    std::cout << "Полученные сообщения:\n";
                    for (auto& msgPtr : messages) {
                        auto msg = *msgPtr; // Разыменование умного указателя, чтобы получить объект Message
                        if (msg.getPolychatel() == userName || msg.getOtpravitel() == userName) {
                            std::cout << msg.getText() << " - Сообщение от пользователя :" << msg.getOtpravitel() << "\n";
                        }
                    }

                    std::cout << "Выберите действие" << std::endl;
                    std::cout << "1. Отправить сообщение всем" << std::endl;
                    std::cout << "2. Отправить сообщение конкретному пользователю" << std::endl;
                    std::cout << "3. Выйти из аккаунта" << std::endl;
                    std::cin >> choice1;

                    switch (choice1) {
                    case 1: {
                        std::string text, otpravitel = userName;
                        std::cin.ignore();
                        std::cout << "Введите сообщение" << std::endl;
                        std::getline(std::cin, text);
                        chat.addMessage(text, userName);
                        break;
                    }
                    case 2: {
                        std::string text, otpravitel = userName, polychatel;
                        std::cin.ignore();
                        std::cout << "Введите имя получателя сообщения" << std::endl;
                        std::getline(std::cin, polychatel);
                        std::cout << "Введите сообщение" << std::endl;
                        std::getline(std::cin, text);
                        chat.userMessage(text, otpravitel, polychatel);
                        break;
                    }
                    case 3: {
                        chat.logout();
                        std::cout << "Выход из аккаунта" << std::endl;
                        break;
                    }
                    default:
                        std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
                        break;
                    }

                    if (choice1 == 3) {
                        break;
                    }
                }
            }
            break;
        }
        case 0: {
            std::cout << "Выход из программы." << std::endl;
            break;
        }
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
            break;
        }
    }

    return 0;
}