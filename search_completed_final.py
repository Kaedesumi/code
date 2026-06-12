# search.py
# ---------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).

MAX_DEPTH = 1000

"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in searchAgents.py).
"""

import util


class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
        util.raiseNotDefined()

    def isGoalState(self, state):
        util.raiseNotDefined()

    def getSuccessors(self, state):
        util.raiseNotDefined()

    def getCostOfActions(self, actions):
        util.raiseNotDefined()


def tinyMazeSearch(problem):
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    return [s, s, w, s, w, w, s, w]


def depthFirstSearch(problem):
    start = problem.getStartState()
    if problem.isGoalState(start):
        return []

    frontier = util.Stack()
    frontier.push((start, []))
    visited = set()

    while not frontier.isEmpty():
        state, actions = frontier.pop()

        if state in visited:
            continue
        visited.add(state)

        if problem.isGoalState(state):
            return actions

        for successor, action, _ in problem.getSuccessors(state):
            if successor not in visited:
                frontier.push((successor, actions + [action]))

    return []


def breadthFirstSearch(problem):
    start = problem.getStartState()
    if problem.isGoalState(start):
        return []

    frontier = util.Queue()
    frontier.push((start, []))
    visited = {start}

    while not frontier.isEmpty():
        state, actions = frontier.pop()

        if problem.isGoalState(state):
            return actions

        for successor, action, _ in problem.getSuccessors(state):
            if successor not in visited:
                visited.add(successor)
                frontier.push((successor, actions + [action]))

    return []


def iterativeDeepeningSearch(problem):
    def depthLimitedSearch(problem, limit):
        start = problem.getStartState()
        if problem.isGoalState(start):
            return []

        frontier = util.Stack()
        frontier.push((start, [], 0))
        best_depth = {start: 0}

        while not frontier.isEmpty():
            state, actions, depth = frontier.pop()

            if problem.isGoalState(state):
                return actions

            if depth == limit:
                continue

            for successor, action, _ in problem.getSuccessors(state):
                new_depth = depth + 1
                if successor not in best_depth or new_depth < best_depth[successor]:
                    best_depth[successor] = new_depth
                    frontier.push((successor, actions + [action], new_depth))

        return None

    for depth_limit in range(MAX_DEPTH + 1):
        result = depthLimitedSearch(problem, depth_limit)
        if result is not None:
            return result

    return []


def uniformCostSearch(problem):
    start = problem.getStartState()
    if problem.isGoalState(start):
        return []

    frontier = util.PriorityQueue()
    frontier.push((start, [], 0), 0)
    best_cost = {start: 0}

    while not frontier.isEmpty():
        state, actions, cost_so_far = frontier.pop()

        if cost_so_far > best_cost.get(state, float("inf")):
            continue

        if problem.isGoalState(state):
            return actions

        for successor, action, step_cost in problem.getSuccessors(state):
            new_cost = cost_so_far + step_cost
            if new_cost < best_cost.get(successor, float("inf")):
                best_cost[successor] = new_cost
                frontier.push((successor, actions + [action], new_cost), new_cost)

    return []


def nullHeuristic(state, problem=None):
    return 0


def aStarSearch(problem, heuristic=nullHeuristic):
    start = problem.getStartState()
    if problem.isGoalState(start):
        return []

    frontier = util.PriorityQueue()
    frontier.push((start, [], 0), heuristic(start, problem))
    best_cost = {start: 0}

    while not frontier.isEmpty():
        state, actions, cost_so_far = frontier.pop()

        if cost_so_far > best_cost.get(state, float("inf")):
            continue

        if problem.isGoalState(state):
            return actions

        for successor, action, step_cost in problem.getSuccessors(state):
            new_cost = cost_so_far + step_cost
            if new_cost < best_cost.get(successor, float("inf")):
                best_cost[successor] = new_cost
                priority = new_cost + heuristic(successor, problem)
                frontier.push((successor, actions + [action], new_cost), priority)

    return []


bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch
iter = iterativeDeepeningSearch