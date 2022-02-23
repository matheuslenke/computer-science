// Generated from /Users/matheuslenke/Developer/College/computer-science/compilers/Lab05/ezlang-antlr/EZParser.g by ANTLR 4.8

    package parser;

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class EZParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		WS=1, COMMENTS=2, BEGIN=3, BOOL=4, ELSE=5, END=6, FALSE=7, IF=8, INT=9, 
		PROGRAM=10, READ=11, REAL=12, REPEAT=13, STRING=14, THEN=15, TRUE=16, 
		UNTIL=17, VAR=18, WRITE=19, ASSIGN=20, EQ=21, LPAR=22, LT=23, MINUS=24, 
		OVER=25, PLUS=26, RPAR=27, SEMI=28, TIMES=29, INT_VAL=30, REAL_VAL=31, 
		STR_VAL=32, ID=33;
	public static final int
		RULE_program = 0, RULE_vars_sect = 1, RULE_var_decl = 2, RULE_type_spec = 3, 
		RULE_stmt_sect = 4, RULE_stmt = 5, RULE_assign_stmt = 6, RULE_if_stmt = 7, 
		RULE_read_stmt = 8, RULE_repeat_stmt = 9, RULE_write_stmt = 10, RULE_expr = 11;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "vars_sect", "var_decl", "type_spec", "stmt_sect", "stmt", 
			"assign_stmt", "if_stmt", "read_stmt", "repeat_stmt", "write_stmt", "expr"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, "'begin'", "'bool'", "'else'", "'end'", "'false'", 
			"'if'", "'int'", "'program'", "'read'", "'real'", "'repeat'", "'string'", 
			"'then'", "'true'", "'until'", "'var'", "'write'", "':='", "'='", "'('", 
			"'<'", "'-'", "'/'", "'+'", "')'", "';'", "'*'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "WS", "COMMENTS", "BEGIN", "BOOL", "ELSE", "END", "FALSE", "IF", 
			"INT", "PROGRAM", "READ", "REAL", "REPEAT", "STRING", "THEN", "TRUE", 
			"UNTIL", "VAR", "WRITE", "ASSIGN", "EQ", "LPAR", "LT", "MINUS", "OVER", 
			"PLUS", "RPAR", "SEMI", "TIMES", "INT_VAL", "REAL_VAL", "STR_VAL", "ID"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "EZParser.g"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public EZParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgramContext extends ParserRuleContext {
		public TerminalNode PROGRAM() { return getToken(EZParser.PROGRAM, 0); }
		public TerminalNode ID() { return getToken(EZParser.ID, 0); }
		public TerminalNode SEMI() { return getToken(EZParser.SEMI, 0); }
		public Vars_sectContext vars_sect() {
			return getRuleContext(Vars_sectContext.class,0);
		}
		public Stmt_sectContext stmt_sect() {
			return getRuleContext(Stmt_sectContext.class,0);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(24);
			match(PROGRAM);
			setState(25);
			match(ID);
			setState(26);
			match(SEMI);
			setState(27);
			vars_sect();
			setState(28);
			stmt_sect();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Vars_sectContext extends ParserRuleContext {
		public TerminalNode VAR() { return getToken(EZParser.VAR, 0); }
		public List<Var_declContext> var_decl() {
			return getRuleContexts(Var_declContext.class);
		}
		public Var_declContext var_decl(int i) {
			return getRuleContext(Var_declContext.class,i);
		}
		public Vars_sectContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vars_sect; }
	}

	public final Vars_sectContext vars_sect() throws RecognitionException {
		Vars_sectContext _localctx = new Vars_sectContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_vars_sect);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(30);
			match(VAR);
			setState(34);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << BOOL) | (1L << INT) | (1L << REAL) | (1L << STRING))) != 0)) {
				{
				{
				setState(31);
				var_decl();
				}
				}
				setState(36);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Var_declContext extends ParserRuleContext {
		public Type_specContext type_spec() {
			return getRuleContext(Type_specContext.class,0);
		}
		public TerminalNode ID() { return getToken(EZParser.ID, 0); }
		public TerminalNode SEMI() { return getToken(EZParser.SEMI, 0); }
		public Var_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_var_decl; }
	}

	public final Var_declContext var_decl() throws RecognitionException {
		Var_declContext _localctx = new Var_declContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_var_decl);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(37);
			type_spec();
			setState(38);
			match(ID);
			setState(39);
			match(SEMI);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Type_specContext extends ParserRuleContext {
		public Type_specContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type_spec; }
	 
		public Type_specContext() { }
		public void copyFrom(Type_specContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class RealTypeContext extends Type_specContext {
		public TerminalNode REAL() { return getToken(EZParser.REAL, 0); }
		public RealTypeContext(Type_specContext ctx) { copyFrom(ctx); }
	}
	public static class StrTypeContext extends Type_specContext {
		public TerminalNode STRING() { return getToken(EZParser.STRING, 0); }
		public StrTypeContext(Type_specContext ctx) { copyFrom(ctx); }
	}
	public static class IntTypeContext extends Type_specContext {
		public TerminalNode INT() { return getToken(EZParser.INT, 0); }
		public IntTypeContext(Type_specContext ctx) { copyFrom(ctx); }
	}
	public static class BoolTypeContext extends Type_specContext {
		public TerminalNode BOOL() { return getToken(EZParser.BOOL, 0); }
		public BoolTypeContext(Type_specContext ctx) { copyFrom(ctx); }
	}

	public final Type_specContext type_spec() throws RecognitionException {
		Type_specContext _localctx = new Type_specContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_type_spec);
		try {
			setState(45);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BOOL:
				_localctx = new BoolTypeContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(41);
				match(BOOL);
				}
				break;
			case INT:
				_localctx = new IntTypeContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(42);
				match(INT);
				}
				break;
			case REAL:
				_localctx = new RealTypeContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(43);
				match(REAL);
				}
				break;
			case STRING:
				_localctx = new StrTypeContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(44);
				match(STRING);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Stmt_sectContext extends ParserRuleContext {
		public TerminalNode BEGIN() { return getToken(EZParser.BEGIN, 0); }
		public TerminalNode END() { return getToken(EZParser.END, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public Stmt_sectContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt_sect; }
	}

	public final Stmt_sectContext stmt_sect() throws RecognitionException {
		Stmt_sectContext _localctx = new Stmt_sectContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_stmt_sect);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(47);
			match(BEGIN);
			setState(49); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(48);
				stmt();
				}
				}
				setState(51); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IF) | (1L << READ) | (1L << REPEAT) | (1L << WRITE) | (1L << ID))) != 0) );
			setState(53);
			match(END);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StmtContext extends ParserRuleContext {
		public Assign_stmtContext assign_stmt() {
			return getRuleContext(Assign_stmtContext.class,0);
		}
		public If_stmtContext if_stmt() {
			return getRuleContext(If_stmtContext.class,0);
		}
		public Read_stmtContext read_stmt() {
			return getRuleContext(Read_stmtContext.class,0);
		}
		public Repeat_stmtContext repeat_stmt() {
			return getRuleContext(Repeat_stmtContext.class,0);
		}
		public Write_stmtContext write_stmt() {
			return getRuleContext(Write_stmtContext.class,0);
		}
		public StmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt; }
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_stmt);
		try {
			setState(60);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ID:
				enterOuterAlt(_localctx, 1);
				{
				setState(55);
				assign_stmt();
				}
				break;
			case IF:
				enterOuterAlt(_localctx, 2);
				{
				setState(56);
				if_stmt();
				}
				break;
			case READ:
				enterOuterAlt(_localctx, 3);
				{
				setState(57);
				read_stmt();
				}
				break;
			case REPEAT:
				enterOuterAlt(_localctx, 4);
				{
				setState(58);
				repeat_stmt();
				}
				break;
			case WRITE:
				enterOuterAlt(_localctx, 5);
				{
				setState(59);
				write_stmt();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Assign_stmtContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(EZParser.ID, 0); }
		public TerminalNode ASSIGN() { return getToken(EZParser.ASSIGN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(EZParser.SEMI, 0); }
		public Assign_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assign_stmt; }
	}

	public final Assign_stmtContext assign_stmt() throws RecognitionException {
		Assign_stmtContext _localctx = new Assign_stmtContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_assign_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(62);
			match(ID);
			setState(63);
			match(ASSIGN);
			setState(64);
			expr(0);
			setState(65);
			match(SEMI);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class If_stmtContext extends ParserRuleContext {
		public TerminalNode IF() { return getToken(EZParser.IF, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode THEN() { return getToken(EZParser.THEN, 0); }
		public TerminalNode END() { return getToken(EZParser.END, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public TerminalNode ELSE() { return getToken(EZParser.ELSE, 0); }
		public If_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_if_stmt; }
	}

	public final If_stmtContext if_stmt() throws RecognitionException {
		If_stmtContext _localctx = new If_stmtContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_if_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(67);
			match(IF);
			setState(68);
			expr(0);
			setState(69);
			match(THEN);
			setState(71); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(70);
				stmt();
				}
				}
				setState(73); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IF) | (1L << READ) | (1L << REPEAT) | (1L << WRITE) | (1L << ID))) != 0) );
			setState(81);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ELSE) {
				{
				setState(75);
				match(ELSE);
				setState(77); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(76);
					stmt();
					}
					}
					setState(79); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IF) | (1L << READ) | (1L << REPEAT) | (1L << WRITE) | (1L << ID))) != 0) );
				}
			}

			setState(83);
			match(END);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Read_stmtContext extends ParserRuleContext {
		public TerminalNode READ() { return getToken(EZParser.READ, 0); }
		public TerminalNode ID() { return getToken(EZParser.ID, 0); }
		public TerminalNode SEMI() { return getToken(EZParser.SEMI, 0); }
		public Read_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_read_stmt; }
	}

	public final Read_stmtContext read_stmt() throws RecognitionException {
		Read_stmtContext _localctx = new Read_stmtContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_read_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(85);
			match(READ);
			setState(86);
			match(ID);
			setState(87);
			match(SEMI);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Repeat_stmtContext extends ParserRuleContext {
		public TerminalNode REPEAT() { return getToken(EZParser.REPEAT, 0); }
		public TerminalNode UNTIL() { return getToken(EZParser.UNTIL, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public Repeat_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_repeat_stmt; }
	}

	public final Repeat_stmtContext repeat_stmt() throws RecognitionException {
		Repeat_stmtContext _localctx = new Repeat_stmtContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_repeat_stmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(89);
			match(REPEAT);
			setState(91); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(90);
				stmt();
				}
				}
				setState(93); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IF) | (1L << READ) | (1L << REPEAT) | (1L << WRITE) | (1L << ID))) != 0) );
			setState(95);
			match(UNTIL);
			setState(96);
			expr(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Write_stmtContext extends ParserRuleContext {
		public TerminalNode WRITE() { return getToken(EZParser.WRITE, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(EZParser.SEMI, 0); }
		public Write_stmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_write_stmt; }
	}

	public final Write_stmtContext write_stmt() throws RecognitionException {
		Write_stmtContext _localctx = new Write_stmtContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_write_stmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(98);
			match(WRITE);
			setState(99);
			expr(0);
			setState(100);
			match(SEMI);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	 
		public ExprContext() { }
		public void copyFrom(ExprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ExprRealValContext extends ExprContext {
		public TerminalNode REAL_VAL() { return getToken(EZParser.REAL_VAL, 0); }
		public ExprRealValContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class TimesOverContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode TIMES() { return getToken(EZParser.TIMES, 0); }
		public TerminalNode OVER() { return getToken(EZParser.OVER, 0); }
		public TimesOverContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class PlusMinusContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode PLUS() { return getToken(EZParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(EZParser.MINUS, 0); }
		public PlusMinusContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprStrValContext extends ExprContext {
		public TerminalNode STR_VAL() { return getToken(EZParser.STR_VAL, 0); }
		public ExprStrValContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprParContext extends ExprContext {
		public TerminalNode LPAR() { return getToken(EZParser.LPAR, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode RPAR() { return getToken(EZParser.RPAR, 0); }
		public ExprParContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprFalseContext extends ExprContext {
		public TerminalNode FALSE() { return getToken(EZParser.FALSE, 0); }
		public ExprFalseContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprIdContext extends ExprContext {
		public TerminalNode ID() { return getToken(EZParser.ID, 0); }
		public ExprIdContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprIntValContext extends ExprContext {
		public TerminalNode INT_VAL() { return getToken(EZParser.INT_VAL, 0); }
		public ExprIntValContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class EqLtContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode EQ() { return getToken(EZParser.EQ, 0); }
		public TerminalNode LT() { return getToken(EZParser.LT, 0); }
		public EqLtContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprTrueContext extends ExprContext {
		public TerminalNode TRUE() { return getToken(EZParser.TRUE, 0); }
		public ExprTrueContext(ExprContext ctx) { copyFrom(ctx); }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 22;
		enterRecursionRule(_localctx, 22, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(113);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAR:
				{
				_localctx = new ExprParContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(103);
				match(LPAR);
				setState(104);
				expr(0);
				setState(105);
				match(RPAR);
				}
				break;
			case TRUE:
				{
				_localctx = new ExprTrueContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(107);
				match(TRUE);
				}
				break;
			case FALSE:
				{
				_localctx = new ExprFalseContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(108);
				match(FALSE);
				}
				break;
			case INT_VAL:
				{
				_localctx = new ExprIntValContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(109);
				match(INT_VAL);
				}
				break;
			case REAL_VAL:
				{
				_localctx = new ExprRealValContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(110);
				match(REAL_VAL);
				}
				break;
			case STR_VAL:
				{
				_localctx = new ExprStrValContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(111);
				match(STR_VAL);
				}
				break;
			case ID:
				{
				_localctx = new ExprIdContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(112);
				match(ID);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(126);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(124);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
					case 1:
						{
						_localctx = new TimesOverContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(115);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(116);
						((TimesOverContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==OVER || _la==TIMES) ) {
							((TimesOverContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(117);
						expr(11);
						}
						break;
					case 2:
						{
						_localctx = new PlusMinusContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(118);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(119);
						((PlusMinusContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==MINUS || _la==PLUS) ) {
							((PlusMinusContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(120);
						expr(10);
						}
						break;
					case 3:
						{
						_localctx = new EqLtContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(121);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(122);
						((EqLtContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==EQ || _la==LT) ) {
							((EqLtContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(123);
						expr(9);
						}
						break;
					}
					} 
				}
				setState(128);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 11:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 10);
		case 1:
			return precpred(_ctx, 9);
		case 2:
			return precpred(_ctx, 8);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3#\u0084\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\3\2\3\2\3\2\3\2\3\2\3\2\3\3\3\3\7\3#\n\3\f\3\16\3"+
		"&\13\3\3\4\3\4\3\4\3\4\3\5\3\5\3\5\3\5\5\5\60\n\5\3\6\3\6\6\6\64\n\6\r"+
		"\6\16\6\65\3\6\3\6\3\7\3\7\3\7\3\7\3\7\5\7?\n\7\3\b\3\b\3\b\3\b\3\b\3"+
		"\t\3\t\3\t\3\t\6\tJ\n\t\r\t\16\tK\3\t\3\t\6\tP\n\t\r\t\16\tQ\5\tT\n\t"+
		"\3\t\3\t\3\n\3\n\3\n\3\n\3\13\3\13\6\13^\n\13\r\13\16\13_\3\13\3\13\3"+
		"\13\3\f\3\f\3\f\3\f\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\5\rt\n"+
		"\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\7\r\177\n\r\f\r\16\r\u0082\13\r"+
		"\3\r\2\3\30\16\2\4\6\b\n\f\16\20\22\24\26\30\2\5\4\2\33\33\37\37\4\2\32"+
		"\32\34\34\4\2\27\27\31\31\2\u008d\2\32\3\2\2\2\4 \3\2\2\2\6\'\3\2\2\2"+
		"\b/\3\2\2\2\n\61\3\2\2\2\f>\3\2\2\2\16@\3\2\2\2\20E\3\2\2\2\22W\3\2\2"+
		"\2\24[\3\2\2\2\26d\3\2\2\2\30s\3\2\2\2\32\33\7\f\2\2\33\34\7#\2\2\34\35"+
		"\7\36\2\2\35\36\5\4\3\2\36\37\5\n\6\2\37\3\3\2\2\2 $\7\24\2\2!#\5\6\4"+
		"\2\"!\3\2\2\2#&\3\2\2\2$\"\3\2\2\2$%\3\2\2\2%\5\3\2\2\2&$\3\2\2\2\'(\5"+
		"\b\5\2()\7#\2\2)*\7\36\2\2*\7\3\2\2\2+\60\7\6\2\2,\60\7\13\2\2-\60\7\16"+
		"\2\2.\60\7\20\2\2/+\3\2\2\2/,\3\2\2\2/-\3\2\2\2/.\3\2\2\2\60\t\3\2\2\2"+
		"\61\63\7\5\2\2\62\64\5\f\7\2\63\62\3\2\2\2\64\65\3\2\2\2\65\63\3\2\2\2"+
		"\65\66\3\2\2\2\66\67\3\2\2\2\678\7\b\2\28\13\3\2\2\29?\5\16\b\2:?\5\20"+
		"\t\2;?\5\22\n\2<?\5\24\13\2=?\5\26\f\2>9\3\2\2\2>:\3\2\2\2>;\3\2\2\2>"+
		"<\3\2\2\2>=\3\2\2\2?\r\3\2\2\2@A\7#\2\2AB\7\26\2\2BC\5\30\r\2CD\7\36\2"+
		"\2D\17\3\2\2\2EF\7\n\2\2FG\5\30\r\2GI\7\21\2\2HJ\5\f\7\2IH\3\2\2\2JK\3"+
		"\2\2\2KI\3\2\2\2KL\3\2\2\2LS\3\2\2\2MO\7\7\2\2NP\5\f\7\2ON\3\2\2\2PQ\3"+
		"\2\2\2QO\3\2\2\2QR\3\2\2\2RT\3\2\2\2SM\3\2\2\2ST\3\2\2\2TU\3\2\2\2UV\7"+
		"\b\2\2V\21\3\2\2\2WX\7\r\2\2XY\7#\2\2YZ\7\36\2\2Z\23\3\2\2\2[]\7\17\2"+
		"\2\\^\5\f\7\2]\\\3\2\2\2^_\3\2\2\2_]\3\2\2\2_`\3\2\2\2`a\3\2\2\2ab\7\23"+
		"\2\2bc\5\30\r\2c\25\3\2\2\2de\7\25\2\2ef\5\30\r\2fg\7\36\2\2g\27\3\2\2"+
		"\2hi\b\r\1\2ij\7\30\2\2jk\5\30\r\2kl\7\35\2\2lt\3\2\2\2mt\7\22\2\2nt\7"+
		"\t\2\2ot\7 \2\2pt\7!\2\2qt\7\"\2\2rt\7#\2\2sh\3\2\2\2sm\3\2\2\2sn\3\2"+
		"\2\2so\3\2\2\2sp\3\2\2\2sq\3\2\2\2sr\3\2\2\2t\u0080\3\2\2\2uv\f\f\2\2"+
		"vw\t\2\2\2w\177\5\30\r\rxy\f\13\2\2yz\t\3\2\2z\177\5\30\r\f{|\f\n\2\2"+
		"|}\t\4\2\2}\177\5\30\r\13~u\3\2\2\2~x\3\2\2\2~{\3\2\2\2\177\u0082\3\2"+
		"\2\2\u0080~\3\2\2\2\u0080\u0081\3\2\2\2\u0081\31\3\2\2\2\u0082\u0080\3"+
		"\2\2\2\r$/\65>KQS_s~\u0080";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}