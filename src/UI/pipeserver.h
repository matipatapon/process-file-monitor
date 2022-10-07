#pragma once

#include "../Common/pipehost.h"
#include <windows.h>
#include <QDebug>

class ProcessMonitor;

class LogBuffer;

struct LogInfo;

enum class Commands{
    Unknown,
    SendPermission,
    ReceiveLog
};

class ConnectionGuard{
public:
    ConnectionGuard(HANDLE& pipeHandle):pipeHandle{pipeHandle}{}
    ~ConnectionGuard();

private:
    HANDLE pipeHandle;
};

class PipeServer  : public PipeHost
{
public:
    PipeServer(ProcessMonitor* processMonitor, LogBuffer* logBuffer)
        :processMonitor{processMonitor},
        logBuffer{logBuffer}{
        pipeHandle = createNewPipe(PipeName);
    }

    static std::pair<DWORD, Commands> getCommandAndPidFromRequest(const std::string& Request);
    static LogInfo parseRequest(std::string request);
    void startServerLoop();
private:
    bool SendPermission(const std::string& request);
    bool ReceiveLog(const std::string& request);
    HANDLE pipeHandle;

    ProcessMonitor* processMonitor;
    LogBuffer* logBuffer;
};
