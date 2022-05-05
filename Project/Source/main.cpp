#include "Application.h"

#include "Globals.h"

enum class MainState {
	CREATION,
	INIT,
	UPDATE,
	FINISH,
	EXIT
};

Application* App = nullptr;

int main() {
	int mainReturn = EXIT_FAILURE;
	MainState state = MainState::CREATION;
	while (state != MainState::EXIT) {
		switch (state) {
		case MainState::CREATION:
			App = new Application();
			state = MainState::INIT;
			break;

		case MainState::INIT:
			if (App->Init() == false) {
				state = MainState::EXIT;
			} else {
				state = MainState::UPDATE;
			}
			break;

		case MainState::UPDATE: {
			UpdateStatus updateStatus = App->Update();

			if (updateStatus == UpdateStatus::ERROR) {
				state = MainState::EXIT;
			} else if (updateStatus == UpdateStatus::STOP) {
				state = MainState::FINISH;
			}
			break;
		}

		case MainState::FINISH:
			if (App->CleanUp() == false) {
			} else {
				mainReturn = EXIT_SUCCESS;
			}

			state = MainState::EXIT;
			break;
		}
	}

	delete App;

	return mainReturn;
}
