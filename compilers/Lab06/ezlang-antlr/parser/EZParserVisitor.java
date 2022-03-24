// Generated from EZParser.g by ANTLR 4.9.3

    package parser;

import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link EZParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface EZParserVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link EZParser#program}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgram(EZParser.ProgramContext ctx);
	/**
	 * Visit a parse tree produced by {@link EZParser#vars_sect}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVars_sect(EZParser.Vars_sectContext ctx);
	/**
	 * Visit a parse tree produced by {@link EZParser#var_decl}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVar_decl(EZParser.Var_declContext ctx);
	/**
	 * Visit a parse tree produced by the {@code boolType}
	 * labeled alternative in {@link EZParser#type_spec}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBoolType(EZParser.BoolTypeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code intType}
	 * labeled alternative in {@link EZParser#type_spec}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIntType(EZParser.IntTypeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code realType}
	 * labeled alternative in {@link EZParser#type_spec}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRealType(EZParser.RealTypeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code strType}
	 * labeled alternative in {@link EZParser#type_spec}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStrType(EZParser.StrTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link EZParser#stmt_sect}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStmt_sect(EZParser.Stmt_sectContext ctx);
	/**
	 * Visit a parse tree produced by {@link EZParser#stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStmt(EZParser.StmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link EZParser#assign_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssign_stmt(EZParser.Assign_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link EZParser#if_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIf_stmt(EZParser.If_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link EZParser#read_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRead_stmt(EZParser.Read_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link EZParser#repeat_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRepeat_stmt(EZParser.Repeat_stmtContext ctx);
	/**
	 * Visit a parse tree produced by {@link EZParser#write_stmt}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitWrite_stmt(EZParser.Write_stmtContext ctx);
	/**
	 * Visit a parse tree produced by the {@code exprRealVal}
	 * labeled alternative in {@link EZParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExprRealVal(EZParser.ExprRealValContext ctx);
	/**
	 * Visit a parse tree produced by the {@code timesOver}
	 * labeled alternative in {@link EZParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTimesOver(EZParser.TimesOverContext ctx);
	/**
	 * Visit a parse tree produced by the {@code plusMinus}
	 * labeled alternative in {@link EZParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPlusMinus(EZParser.PlusMinusContext ctx);
	/**
	 * Visit a parse tree produced by the {@code exprStrVal}
	 * labeled alternative in {@link EZParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExprStrVal(EZParser.ExprStrValContext ctx);
	/**
	 * Visit a parse tree produced by the {@code exprPar}
	 * labeled alternative in {@link EZParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExprPar(EZParser.ExprParContext ctx);
	/**
	 * Visit a parse tree produced by the {@code exprFalse}
	 * labeled alternative in {@link EZParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExprFalse(EZParser.ExprFalseContext ctx);
	/**
	 * Visit a parse tree produced by the {@code exprId}
	 * labeled alternative in {@link EZParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExprId(EZParser.ExprIdContext ctx);
	/**
	 * Visit a parse tree produced by the {@code exprIntVal}
	 * labeled alternative in {@link EZParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExprIntVal(EZParser.ExprIntValContext ctx);
	/**
	 * Visit a parse tree produced by the {@code eqLt}
	 * labeled alternative in {@link EZParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEqLt(EZParser.EqLtContext ctx);
	/**
	 * Visit a parse tree produced by the {@code exprTrue}
	 * labeled alternative in {@link EZParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExprTrue(EZParser.ExprTrueContext ctx);
}