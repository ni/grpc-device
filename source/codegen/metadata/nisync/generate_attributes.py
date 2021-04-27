import os
import re
import sys

file = open(os.path.join(sys.path[0], 'attributes.py'), 'r')
lines = file.readlines()
file.close()

syncAttrBase = 1150000

newlines = []
for line in lines:
    syncAttrPrefix = "NISYNC_ATTR_"
    attrPosition = line.find(syncAttrPrefix)
    if (attrPosition >= 0):
        attrNamePosition = attrPosition + len(syncAttrPrefix)
        lineStartingAttrName = line[attrNamePosition:]
        attrNameMatch = re.match(r"\w+", lineStartingAttrName)
        if (attrNameMatch):
            attributeName = attrNameMatch.group(0)
            syncAttrBasePrefix = "NISYNC_ATTR_BASE + "
            attrBasePosition = lineStartingAttrName.find(syncAttrBasePrefix)
            lineStartingAttrValueOffset = lineStartingAttrName[attrBasePosition + len(syncAttrBasePrefix):]
            attrValueOffsetMatch = re.match(r"[0-9]+", lineStartingAttrValueOffset)
            if (attrValueOffsetMatch):
                attributeValue = str(syncAttrBase + int(attrValueOffsetMatch.group(0)))
                newlines.append(attributeValue + ": {")
                newlines.append("    \'name\': \'" + attributeName + "\'")
                newlines.append("},")

with open(os.path.join(sys.path[0], 'newattributes.py'), 'w') as file:
    file.write('\n'.join(newlines))
