#include <bits/stdc++.h> 
graphNode * makeClone(graphNode* node,unordered_map<graphNode*,graphNode*>&mp){
  graphNode *cloneNode = new graphNode(node->data, {});
  mp[node] = cloneNode;
  for (auto neighbour : node->neighbours) {
    if (mp.find(neighbour) != mp.end()) {
      cloneNode->neighbours.push_back(mp[neighbour]);
    } else {
      graphNode *neighbourClone = makeClone(neighbour, mp);
      cloneNode->neighbours.push_back(neighbourClone);
    }
	}
	return cloneNode;
}
graphNode *cloneGraph(graphNode *node){
    unordered_map<graphNode *,graphNode*>mp;
	return makeClone(node,mp);
	return nullptr;
}