
#include "datamanager.h"

DataManager::DataManager()
{

}

DataManager* DataManager::GetInstance()
{
    if (dataManager == nullptr) {
        dataManager = new DataManager();
    }
    return dataManager;
}
