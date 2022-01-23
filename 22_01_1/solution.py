def makeLogs(uid, log):
    return uid + " " + log

def solution(records):
    users  = {}
    logs   = []
    answer = []
    actionString = {"E": "님이 들어왔습니다.", "L": "님이 나갔습니다."}

    for record in records:
        action = record.split(' ')[0][0]
        uid    = record.split(' ')[1]

        if action == "L":                     # Leave
            logs.append(makeLogs(uid, action))
        else:
            users[uid] = record.split(' ')[2] # Change
            if action == "E":                 # Enter
                logs.append(makeLogs(uid, action))

    for log in logs:
        uid    = log.split()[0]
        action = log.split()[1]
        answer.append(users[uid] + actionString[action])

    return answer
